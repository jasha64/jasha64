STITCH_LIST = [
    'fixed_long_0_60.fasta',
    'fixed_long_60_125.fasta',
    'fixed_long_125_185.fasta',
    'fixed_long_185_250.fasta',
    'fixed_long_250_310.fasta',
    'fixed_long_310_375.fasta',
    'fixed_long_375_435.fasta',
    'fixed_long_435_500.fasta'
]

STITCH_RESULT = 'fixed_long.fasta'

# STITCH_LIST = [
#     'matches_0_1000.json',
#     'matches_1000_2000.json',
#     'matches_2000_3000.json',
#     'matches_3000_4000.json',
#     'matches_4000_5000.json'
# ]

# STITCH_RESULT = 'matches.json'

lines = []
for filename in STITCH_LIST:
    with open(filename, 'r') as f:
        for line in f.readlines():
            line = line.strip('\n')
            if line == '':
                continue
            lines.append(line)
with open(STITCH_RESULT, 'w') as f:
    for line in lines:
        f.write(line+'\n')
