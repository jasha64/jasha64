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
		for (int i = 0; i <= n; i++) f[i] = i;
		for (int i = 1, ism; i <= n; i++)
		{
			ism = Read();
			if (ism) f[Find(i)] = Find(0);
			//������milkman����ȨֵΪ0�ı��볬��Դ��0�ŵ����������������ͱ�Ϊһ�����С������������ 
		}
		for (int i = 0; i < m; i++) e[i].init();
		
		sort(e, e + m);
		long long Res = 0;
		for (int i = 0; i < m; i++)
		{
			int v = Find(e[i].s), u = Find(e[i].t);
			if (v == u) continue;
			f[v] = u; Res += e[i].w;
		}
		
		bool Sol = 1;
		for (int i = 1; i <= n; i++)
			if (Find(i) != Find(0)) {cout << "impossible" << endl; Sol = 0; break;}
		if (Sol) cout << Res << endl;
	}
	
	return 0;
}

