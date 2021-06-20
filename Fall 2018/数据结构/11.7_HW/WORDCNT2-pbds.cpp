//SPOJ - word counting 2
//pbds�ⷨ 
//pb_ds(Policy-Based Data Structures)���ڿƼ���Ŀ⣬��STL���ͬ�����ݽṹ���죬����Ҳ���� 
//�˴���������pb_ds�����ȶ���֧���޸�Ԫ�غ�ɾ������ֵԪ�صĹ�������ɸ��⣬�ͱ�������д�� 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

int id;
unordered_map<string, int> mp;
//unordered_map: ���ļ�������ֱ�ӽ���ϣ�����֯��Ͱ������������ 
//������ʿ���map��˳���������map 
//�������򣬵���Ϊ�����˹�ϣ������find��Ȼ�����ڳ���ʱ������ɵ� 
struct HeapNode
{
	string str;
	int cnt;
	HeapNode(string s = "", int c = 0): str(s), cnt(c) {}
	friend bool operator < (const HeapNode& a, const HeapNode& b) //ע�⣬Ĭ���Ǵ���� 
	{
		if (a.cnt != b.cnt) return a.cnt < b.cnt;
		return a.str > b.str;
	}
};
__gnu_pbds::priority_queue<HeapNode> pq;
__gnu_pbds::priority_queue<HeapNode>::point_iterator pos[100001];
//ֵ��һ����ǣ�������д����������using��䣺 
//using namespace std;
//using __gnu_pbds::priority_queue;
//���������priority_queue��ʱ����뱨��ambiguous reference to "priority_queue" 
//��Ȼ����<queue>ͷ�ļ���STL��std::priority_queue��pb_ds���priority_queue�����ɵ� 
//�ⷴӳ��using namespace std;��һ���Ǳ�ڵ����⣨��ʵ�ںܶ๤�̻��������Ǽ��� 
//��һ���ģ�����ƽʱ���㷨��Ŀ����ܶ��������˴��ţ� 
queue<string> q;
void Insert(const string& str)
{
	if (mp.find(str) != mp.end())
	{
		int cur_id = mp[str], ncnt = pos[cur_id]->cnt + 1;
		pq.modify(pos[cur_id], HeapNode(str, ncnt));
	}
	else pos[mp[str] = id++] = pq.push(HeapNode(str, 1));
}
void Delete(const string& str)
{
	int cur_id = mp[str], ncnt = pos[cur_id]->cnt - 1;
	pq.modify(pos[cur_id], HeapNode(str, ncnt));
}
void Query()
{
	cout << pq.top().str << ' ' << pq.top().cnt << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		cout << "Case " << kase << ':' << endl;
		mp.clear(); pq.clear(); id = 0;
		while (!q.empty()) q.pop();
		//һ��ʼWA�˼�������������q��pq����ÿ�ʲ���֮ǰ��ʼ����
		//��ʲ��ʵ���Ŀ����Ҫע��ÿ�ʲ���ǰ�ĳ�ʼ�� 
		//˵���л���pb_ds�Ķ�����clear������STL�Ķ���ֻ��while () pop();������ʵ��̫���� 
		int n, k;
		cin >> n >> k;
		while (n--)
		{
			string s;
			cin >> s;
			if (q.size() == k) {Delete(q.front()); q.pop();}
			Insert(s); q.push(s);
			Query();
		}
	}
	return 0;
}
//�����˵���л�����˵<algorithm>ͷ�ļ���ԭ��֧��make_heap(), push_heap(), pop_heap(), heap_sort() 
//�ȶѵĲ�������������֧���޸ģ��������ǻ���ֻ����pb_ds 

