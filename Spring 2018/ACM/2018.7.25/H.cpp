#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

//�и���ʱ�Ķ����Ż������ж����Ż��� 
inline int Read()
{
	int r = 0;
	bool isNeg = 0;
	char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') {isNeg = 1; c = getchar();}
	while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
	return isNeg ? -r : r;
}

typedef long long ll;
const int N = 100007;
int w[N];

int t[N+N], Head[N], Next[N+N], Top;
inline void AddEdge(int S, int T)
{
	t[Top] = T;
	Next[Top] = Head[S]; Head[S] = Top;
	Top++;
}

ll f[N]; //f[i]��ʾ�����ڵ�i��·������  
int n, fa[N], dep[N], siz[N];
void DFS(int u)
{
	ll l = 0, r = 0; //u�����������Ĵ�С 
	siz[u] = 1;
	for (int i = Head[u]; i; i = Next[i])
	{
		int v = t[i];
		if (v == fa[u]) continue;
		fa[v] = u; dep[v] = dep[u]+1;
		DFS(v);
		siz[u] += siz[v];
		if (l == 0) l = siz[v];
		else r = siz[v]; //��֪������֤u������ӽڵ����������2�� 
	}
	ll p = n-1 - l - r; //���г�ȥ��uΪ������ʣ��Ľڵ��� 
	f[u] = (l*r + r*p + p*l + n-1) * 2 + 1;
	//����iΪһ�˵�·����Ϊ2(lr+ur+lu)����iΪһ�˵�·����Ϊ2(n-1)������2��ԭ������������ͼ����iΪ���˵�·����Ϊ1����·��i->i��
}
void Make_Tree() {fa[n] = 0; dep[n] = 1; DFS(n);}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) w[i] = Read();
		memset(Head, 0, sizeof(Head)); Top = 2;
		for (int i = 0, u, v; i < n-1; i++)
		{
			u = Read(); v = Read();
			AddEdge(u, v); AddEdge(v, u);
		}

		Make_Tree();
		//Res == 0: �Ѿ�����SUM == 0
		ll SUM = 0;
		for (int i = 1; i <= n; i++) SUM += w[i] * f[i];
		if (SUM == 0) {cout << 0 << endl; continue;}
		//Res == 1: SUM != 0���Ҵ��ڽڵ�uʹ��SUM % f[u] == 0
		bool Sol1 = 0;
		for (int i = 1; i <= n; i++)
			if (SUM % f[i] == 0)
			{
				cout << 1 << ' ' << i << endl;
				Sol1 = 1;
				break;
			}
		if (Sol1) continue;
		//Res == 2: ������������������� 
		int o = 1;
		for (int i = 2; i <= n; i++)
			if (dep[o] < dep[i]) o = i;
		cout << 2 << ' ' << o << ' ' << fa[o] << endl;
	}

	return 0;
}

