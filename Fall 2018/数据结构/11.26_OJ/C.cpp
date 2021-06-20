/*
������Щ�������ֱ���Ķ˵㣬�������һֱ��(u, v) 
˼�������˵�����ֱ֪���˵�Ĺ�ϵ����lenΪֱ�����ȣ����ѷ��֣� 
��lenΪż������xΪֱ�����е㣬������x������Զ�ĵ㶼������ֱ���˵� 
��lenΪ��������(a, b)Ϊֱ�����м��һ���ߣ���a������Զ�ĵ㡢��b������Զ�ĵ㶼������ֱ���˵� 
�Ӷ��ó�����һ����������u������Զ�ĵ㡢��v������Զ�ĵ㶼������ֱ���˵� 
*/
/*
������ʵ�ǵ��ҹ��ɵ��⣬Ӧ�û�ͼ���ҹ��� 
��ʱ��������ʱ������ʶ��Ϊ����һ����DP��������е�ʱ�䶼������DP�ˣ�Ҳ��û�������� 
���������ǣ�һ������������������������ͣ��������ͷ��������˼�������Ŀ��û���������� 
*/
#include <iostream>
using namespace std;

const int N = 100001;
int to[N+N], Head[N], Next[N+N];
inline void AddEdge(int v, int u, int j) {to[j] = u; Next[j] = Head[v]; Head[v] = j;}
int dep[N], g[N];
bool flag[N]; 
void DFS(int v, int fa)
{
	g[v] = 0;
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa) continue;
		dep[u] = dep[v] + 1; DFS(u, v);
		g[v] = max(g[v], g[u] + 1);
	}
}
void Make_Tree(int v) {dep[v] = 0; DFS(v, 0);}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1, j = 2, v, u; i < n; i++) {cin >> v >> u; AddEdge(v, u, j++); AddEdge(u, v, j++);}
	
	Make_Tree(1);
	int nr = 1;
	for (int v = 2; v <= n; v++)
		if (dep[v] > dep[nr]) nr = v;
	Make_Tree(nr);
	int mx = 0;
	for (int v = 1; v <= n; v++)
		if (dep[v] > mx) {mx = dep[v]; nr = v;}
	for (int v = 1; v <= n; v++)
		if (dep[v] == mx) flag[v] = 1;
	Make_Tree(nr);
	for (int v = 1; v <= n; v++)
		if (dep[v] == mx) flag[v] = 1;
	
	int res = 0;
	for (int v = 1; v <= n; v++)
		if (flag[v]) res++;
	cout << res << endl;
	return 0;
}

