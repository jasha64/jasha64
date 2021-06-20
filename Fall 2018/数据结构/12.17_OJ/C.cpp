//DP
//���׷��֣����ڸ���a, b, c��ֽƬ����һ���ܱ�Ψһһ��c+1��ֽƬ���ǣ�ֱ��DP���� 
/*
�����ܿγ�����Ӱ�죬��������Ϊ��DS�⣬Ȼ����������� 
��Ҳ��û�취���� 
*/
#include <iostream>
#include <unordered_map>
using namespace std;

#define umap unordered_map
umap<int, umap<int, umap<int, int> > > f; //unordered_map��ά���� 
#undef umap
inline int Query(int a, int b, int c) //��ѯf[a][b][c]���������ڼ�����f[a][b][c]������0 
{
	if (f[a][b].count(c) == 0) f[a][b][c] = 0;
	return f[a][b][c];
}
inline void Add(int a, int b, int c) {Query(a, b, c); f[a][b][c]++;} //��f[a][b][c]��һ���������ڼ�����f[a][b][c]����ֵΪ1 

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c;
		cout << Query(a, b, c) << endl;
		Add(a, b, c);
		while (c < n) Add(a /= 2, b /= 2, ++c);
	}
	
	return 0;
}

