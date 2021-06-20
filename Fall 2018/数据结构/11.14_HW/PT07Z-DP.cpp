//SPOJ - longest path in a tree
//DP
//�������ڸ�����Ϣ�������Ͽ����������·��DP�ⷨ��
//��������һ�ڵ�vΪ������������g[v]Ϊ��һ�����и����ڵ�ľ�������ֵ���׼�g[v] = max{g[u] + 1}��u��v���ӽڵ� 
//������һ�ڵ�rΪ���������е��·��f[v] = g[u] + g[v] + 1������u��v��r���ӽڵ���gֵǰ����� 
//��������ָ��һ�����ڵ㣬���ϲ������ɣ�����Ϊmax{f[v] | v�����ϵĽڵ� 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10001;
int to[N+N], Head[N], Next[N+N];
inline void AddEdge(int u, int v, int i) {to[i] = v; Next[i] = Head[u]; Head[u] = i;}
int f[N], fa[N], maxlen; //f[v]��ʾ��vΪ���������и����ڵ�ľ�������ֵ 
inline void Tension(int& a, int b) {if (a < b) a = b;}
void DFS(int v) //��������ɽڵ�v��fֵ�ļ��� 
{
	f[v] = 0;
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa[v]) continue;
		fa[u] = v; DFS(u);
		int curlen = f[u] + 1;
		Tension(maxlen, f[v] + curlen);
		//��ʱf[v]�洢���Ƿ��ʵ�u��ǰ���ʵ��ӽڵ���f�����ֵ������д����ȷ��ȡ�����ֵ�ʹδ�ֵ�����Ҳ�������û���ӽڵ��ֻ��1���ӽڵ����� 
		Tension(f[v], curlen);
	}
}
void Make_Tree(int v) {fa[v] = 0; DFS(v);}

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
	cout << maxlen << endl;
	
	return 0;
}

