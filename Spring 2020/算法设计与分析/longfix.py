# 可指定范围，用于支持多线程
# 运行程序后，输入两个参数L、R，含义是计算第L条～第R条（左闭右开）之间的长序列的修补结果。

import json
import math
from tqdm import tqdm
import Levenshtein

PARAM_FILE = 'param.json'
LONG_FILE = 'long.fasta'
SHORT_1_FILE = 'short_1.fasta'
SHORT_2_FILE = 'short_2.fasta'
FIXED_LONG_FILE = 'fixed_long'
MATCHES_FILE = 'matches'
MAXDIS = 0
RANGE_L = 0
RANGE_R = 1000

def fix_long_data_by_matches(long_data, match_info):
    match_info = sorted(match_info, key=lambda x: x['pos'])  # 按匹配点排序
    long = long_data['str']
    new_match_info = []
    new_long = ''

    now_que = []
    now_pos = 0
    for now_pos in range(len(long)):
        # 将新的匹配信息加入队列(now_que)
        while now_pos < len(match_info) and match_info[now_pos]['pos'] <= now_pos:
            now_que.append(match_info[now_pos])
            now_pos += 1
        
        # 若match_info匹配点在当前范围内，则加到new_match_info
        while len(now_que) > 0 and now_que[0]['pos']+len(now_que[0]['str']) <= now_pos:
            new_match_info.append(now_que[0])
            now_que.pop(0)
        
        # 让所有匹配的短序列对长序列当前字符进行“投票”
        vote = {'A': 0, 'T': 0, 'G': 0, 'C': 0}
        vote[long[now_pos]] = 1
        vote_max = 1
        vote_char = long[now_pos]
        for match in now_que:
            vote[match['str'][now_pos-match['pos']]] += 1
        for k, v in vote.items():
            if v > vote_max:  # 统计得票最多的字符
                vote_max = v
                vote_char = k
        new_long += vote_char  # 加到修复后长序列尾

    # 若match_info匹配点在当前范围内，则加到new_match_info（对最后一次循环）
    while len(now_que) > 0:
        new_match_info.append(now_que[0])
        now_que.pop(0)

    fixed_long_data = {'name': long_data['name']+'(fixed)', 'str': new_long}
    return fixed_long_data, new_match_info

def match_short_data(long_data, short_data):
    long = long_data['str']
    short = short_data['str']
    mindis = -1
    minpos = 0
    for i in range(len(long)-len(short)+1):
        dis = Levenshtein.hamming(short, long[i:i+len(short)])
        if mindis == -1 or dis < mindis:  # 更新汉明距离最小位点（匹配点）
            mindis = dis
            minpos = i
    match = {'name': short_data['name'], 'pos': minpos, 'dis': mindis,
        'str': short_data['str'] }
    return match

def match_short_dataset(long_data, short_dataset):
    match_info = []
    for short_data in short_dataset:
        match = match_short_data(long_data, short_data)
        if match['dis'] < MAXDIS:
            match_info.append(match)
    return match_info

def get_match_info(long_dataset, short_datasets):
    mixed_short_dataset = []
    for short_dataset in short_datasets:
        mixed_short_dataset.extend(short_dataset)

    for i, long_data in enumerate(tqdm(long_dataset)):
        # 不在区间内
        if i < RANGE_L:
            continue
        
        # 完成区间目标
        if i == RANGE_R:
            exit('Done range %d to %d' % (RANGE_L, RANGE_R))

        match_info = match_short_dataset(long_data, mixed_short_dataset)  # 求匹配
        fixed_data, match_info = fix_long_data_by_matches(long_data, match_info)  # “修补”长序列

        # 写结果
        with open(FIXED_LONG_FILE, 'a') as f:
            f.write(fixed_data['name']+'\n')
            f.write(fixed_data['str']+'\n')
        with open(MATCHES_FILE, 'a') as f:
            f.write(json.dumps(match_info)+',\n')


def read_fasta(filename):
    content = []
    print('Load data', filename)
    with open(filename, 'r') as f:
        lines = f.readlines()
        name = ''
        for i, line in enumerate(lines):
            if i % 2 == 0:
                name = line.strip()
            else:
                content.append({'name': name, 'str': line.strip('\n')})
    return content

def get_rev_comp_data(content):
    comp = {'A': 'T', 'G': 'C', 'C': 'G', 'T': 'A'}
    return [{
        'name': data['name'],
        'str': ''.join([comp[c] for c in data['str']][::-1])
        } for data in content]

if __name__ == "__main__":
    # 指定范围
    RANGE_L = eval(input('RANGE_L:'))
    RANGE_R = eval(input('RANGE_R:'))
    FIXED_LONG_FILE = FIXED_LONG_FILE + '_' + str(RANGE_L) + '_' + str(RANGE_R) + '.fasta'
    MATCHES_FILE = MATCHES_FILE + '_' + str(RANGE_L) + '_' + str(RANGE_R) + '.json'

    # 读入数据并扩展反向互补串
    with open(PARAM_FILE, 'r') as f:
        PARAM = json.loads(f.read())
    fs1 = read_fasta(SHORT_1_FILE)
    fs2 = read_fasta(SHORT_2_FILE)
    fl = read_fasta(LONG_FILE)
    fs1_rc = get_rev_comp_data(fs1)
    fs2_rc = get_rev_comp_data(fs2)
    # fl_rc = get_comp_rev_data(fl)  这一部分的修补结果就是前一部分(fl)的结果的反向互补，故略去
    
    # 计算“修补”长序列
    MAXDIS = math.floor(PARAM['short_read_length'] *
        (PARAM['short_read_error_rate']+PARAM['long_read_error_rate'])+5)  # 汉明距离最大允许值
    print('Fixing long_read')
    get_match_info(fl, [fs1, fs2, fs1_rc, fs2_rc])
    
