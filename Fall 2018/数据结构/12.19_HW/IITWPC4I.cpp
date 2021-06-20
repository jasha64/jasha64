//SPOJ - Petya and Repairment of Roads
//��С��������Kruskal��ʽ 
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return r;
}
const int N = 100001;
int f[N];
int Find(int x)
{
	if (f[x] == x) return x;
	return f[x] = Find(f[x]);
}
bool ism[N];
struct Edge
{
	int s, t, w;
	void init() {s = Read(); t = Read(); w = Read();}
	friend bool operator < (const Edge& a, const Edge& b) {return a.w < b.w;}
} e[200001];


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) f[i] = i;
		for (int i = 1; i <= n; i++) ism[i] = Read();
		for (int i = 0; i < m; i++) e[i].init();
		
		sort(e, e + m);
		long long Res = 0;
		for (int i = 0; i < m; i++)
		{
			int v = Find(e[i].s), u = Find(e[i].t);
			if (v == u || (ism[v] && ism[u])) continue;
			//�����������ߵ������������ɻ����������������˵���ͨ�������Ѿ���milkman�� 
			ism[u] = ism[v] || ism[u]; f[v] = u; Res += e[i].w;
		}
		
		bool Sol = 1;
		for (int i = 1; i <= n; i++)
			if (!ism[Find(i)]) {cout << "impossible" << endl; Sol = 0; break;}
		if (Sol) cout << Res << endl;
	}
	
	return 0;
}

