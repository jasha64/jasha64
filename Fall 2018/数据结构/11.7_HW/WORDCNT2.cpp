//SPOJ - word counting 2
//�� 
//һ��ĶѲ�֧���޸�Ԫ�����ֲ������������ǲ�ȡ��Dijkstra�㷨���Ƶķ�ʽ����ܣ� 
//ÿ�θĶ�ʱ������Ķ�ǰ��Ԫ�أ�ÿ��ȡ���Ѷ�ʱ�ж����Ԫ���ǲ����ѹ��ڣ�����ǣ��������Ԫ�� 
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

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
unordered_map<string, int> mp;
queue<string> q;
priority_queue<HeapNode> pq;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		mp.clear();
		while (!pq.empty()) pq.pop();
		while (!q.empty()) q.pop();
		cout << "Case " << kase << ':' << endl;
		int n, k;
		cin >> n >> k;
		while (n--)
		{
			string s;
			cin >> s;
			if (q.size() == k)
			{
				string c = q.front(); q.pop();
				mp[c]--; pq.push(HeapNode(c, mp[c]));
			}
			q.push(s);
			if (mp.find(s) == mp.end()) mp[s] = 1;
			else mp[s]++;
			pq.push(HeapNode(s, mp[s]));
			while (mp[pq.top().str] != pq.top().cnt) pq.pop(); //�������й���Ԫ�� 
			cout << pq.top().str << ' ' << pq.top().cnt << endl;
		}
	}
	
	return 0;
}
//�����˵���л�����˵<algorithm>ͷ�ļ���ԭ��֧��make_heap(), push_heap(), pop_heap(), heap_sort() 
//�ȶѵĲ�������������֧���޸ģ�Ҫ��ʵ���޸�Ԫ�ػ���ֻ����pb_ds 

