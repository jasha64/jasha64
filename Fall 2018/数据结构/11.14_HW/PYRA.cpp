//SPOJ - treeramids
//DFS
//���Ⱥ��������������BFS����������һ����������Ͳ���������������һ������ 
//��Ϊ�Ե����ϵ�BFSʵ������鷳������ֱ�Ӳ���DFS����ΪDFSҲ�Ǳ������ӽڵ�Ż�ع飬
//������Ȼ���������ȷ�𰸣�������ع�Ĺ�����ɼ��㼴�� 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10001;
int to[N+N], Head[N], Next[N+N];
inline void AddEdge(int u, int v, int j) {to[j] = v; Next[j] = Head[u]; Head[u] = j;}
int f[N], fa[N];
void DFS(int v)
{
	f[v] = 1;
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa[v]) continue;
		fa[u] = v; DFS(u);
		f[v] = f[v] + f[u] + 1; //ÿ����һ���ӽڵ��Ҫ����1�ļ��������f[v] += f[u] + 1; 
	}
}
void Make_Tree(int v) {fa[v] = 0; DFS(v);}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		memset(Head, 0, sizeof(Head)); //��ʲ���ʱ��ÿ�ʱ����ʼ���ڽӾ����Head 
		int n;
		cin >> n;
		for (int i = 1, j = 2, u, v; i < n; i++)
		{
			cin >> u >> v;
			AddEdge(u, v, j++); AddEdge(v, u, j++);
		}
		
		Make_Tree(0);
		int res = 0;
		for (int i = 0; i < n; i++) res += f[i];
		cout << res << endl;
	}
	
	return 0;
}

