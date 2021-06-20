//������ֱ���м��� 
//����������ֱ���Ķ�̬�滮�㷨��ֻ����DP�����м�¼������ 
//f[v] = max{g[u1] + w(v, u1) + g[u2] + w(v, u2) | u1, u2Ϊv���ӽڵ�}
//gcnt[v] = sum{gcnt[u1] * gcnt[u2] | g[u1] + w(v, u1) + g[u2] + w(v, u2) == f[v]}
//maxlen = max{f[v] | v�����еĶ���}
//maxcnt = sum{gcnt[v] | f[v] == maxlen} 
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100001;
int to[N+N], Head[N], Next[N+N], w[N+N];
inline void AddEdge(int v, int u, int W, int j) {to[j] = u; w[j] = W; Next[j] = Head[v]; Head[v] = j;}
int g[N], gcnt[N];
int maxlen, maxcnt;
void DFS(int v, int fa) //����Ҫ����faʱ�����԰�����Ϊ�������ݣ�ʡ��һ��fa���� 
{
	g[v] = 0; gcnt[v] = 1;
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa) continue;
		DFS(u, v);
		int curlen = g[u] + w[i];
		if (g[v] + curlen > maxlen) {maxlen = g[v] + curlen; maxcnt = gcnt[v] * gcnt[u];} //����ֱ������ 
		else if (g[v] + curlen == maxlen) maxcnt += gcnt[v] * gcnt[u]; //����ֱ������ 
		if (curlen > g[v]) {g[v] = curlen; gcnt[v] = gcnt[u];} //����g[v] 
		else if (curlen == g[v]) gcnt[v] += gcnt[u]; //����g[v]������ 
	}
}
inline void Make_Tree(int v) {DFS(v, 0);}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		memset(Head, 0, sizeof(Head)); maxlen = 0;
		for (int i = 1, j = 2, v, u, w; i < n; i++) {cin >> v >> u >> w; AddEdge(v, u, w, j++); AddEdge(u, v, w, j++);}
		Make_Tree(1);
		cout << maxlen << ' ' << maxcnt << endl;
	}
	
	return 0;
}

