//SPOJ - Cobbled streets
//��С������ 
//��Ϊ�ǳ���ͼ���˴�����Prim�㷨 
#include <iostream>
#include <cstdio>
#include <cctype>
#include <queue>
#include <cstring>
using namespace std;

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return r;
}
const int N = 1001, M = 300001;
struct Edge
{
	int t, w, Next;
	friend bool operator < (const Edge& a, const Edge& b) {return a.w > b.w;}
} e[M+M];
int Head[N];
inline void AddEdge(int s, int t, int w, int j)
{
	e[j].t = t; e[j].w = w;
	e[j].Next = Head[s]; Head[s] = j;
}
bool vis[N];
priority_queue<Edge> pq;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(Head, 0, sizeof(Head)); //ʹ���ڽӱ�ʱ��ÿ�ʲ�����س�ʼ��Head 
		int p, n, m;
		cin >> p >> n >> m;
		for (int i = 0, j = 2, v, u, w; i < m; i++)
		{
			v = Read(); u = Read(); w = Read();
			AddEdge(v, u, w, j++); AddEdge(u, v, w, j++);
		}
		
		unsigned int Res = 0;
		vis[1] = 1;
		for (int i = Head[1]; i != 0; i = e[i].Next) pq.push(e[i]);
		while (!pq.empty())
		{
			Edge cur = pq.top(); pq.pop();
			int u = cur.t;
			if (vis[u]) continue;
			vis[u] = 1; Res += cur.w;
			for (int i = Head[u]; i != 0; i = e[i].Next) pq.push(e[i]);
		}
		cout << (Res *= p) << endl;
	}
	
	return 0;
}

