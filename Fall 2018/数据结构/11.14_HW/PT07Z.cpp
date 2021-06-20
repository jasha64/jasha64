//SPOJ - longest path in a tree
//DFS
//�������·��DFS�����ǣ�������ָ��һ����Ϊ����ͨ��DFS���������ṹ��Ȼ��ѡ����ʱ 
//������Ľڵ㣬����ѡ��������ڵ�Ϊ�����������������ȼ�Ϊ������·�ĳ��� 
//�����ǣ��������ĸ���Ϊ��������Ľڵ�һ���ڴ�����·�� 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10001;
int to[N+N], Head[N], Next[N+N]; //to��Next���ڴ�ߣ���Ҫ��2n+2�Ĵ�С������ͼ�� 
inline void AddEdge(int u, int v, int i) {to[i] = v; Next[i] = Head[u]; Head[u] = i;}
int fa[N], dep[N];
void DFS(int v)
{
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa[v]) continue;
		fa[u] = v; dep[u] = dep[v] + 1; DFS(u);
	}
}
void Make_Tree(int v) {fa[v] = dep[v] = 0; DFS(v);}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1, j = 2, u, v; i < n; i++)
	{
		cin >> u >> v;
		AddEdge(u, v, j++); AddEdge(v, u, j++);
	}
	
	Make_Tree(1);
	int cur = 1;
	for (int i = 2; i <= n; i++)
		if (dep[i] > dep[cur]) cur = i;
	Make_Tree(cur);
	
	cout << *max_element(dep+1, dep+n+1) << endl;
	return 0;
}

