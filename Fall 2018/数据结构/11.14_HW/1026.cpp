//10.131.235.233 - 1026
//̰�� 
//����̰���㷨�ı�׼֤����������֤�����㷨����ȷ��: 
//����DFS�����������mn[v]��¼��vΪ�������д���ϵ��(ti)����Сֵ��sum[v]��¼������ 
//Ȩֵ(wi)�ĺͣ�lim[v]��ʾ�ڵ�v������ֵ(ci)�����ڷ�����ÿ������ӽڵ����� 
//sum[v] < lim[v]������������vΪ�������д���ϵ����С�ĵ��ϼ�Ȩֵlim[v] - sum[v] 
//����Դ𰸵Ĺ�����(lim[v] - sum[v]) * mn[v]����������ʹ��sum[v] = lim[v]�������� 
//��Ŀ��Ҫ�� 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100001;
int mn[N], Left[N], Right[N], lim[N], cost[N];
long long sum[N];
//һ��ʼд����int, �����ݷ�Χ����һ��ҳ�ύ��¼��WA 
//���ݷ�Χ�Ĺ��㻹Ҫ��ǿ��ʶ 
inline void AddChild(int v, int u) {Right[u] = Left[v]; Left[v] = u;} //��������ֵ� 
long long res = 0;
void DFS(int v)
{
	if (Left[v] == 0) {mn[v] = cost[v]; sum[v] = lim[v]; res += lim[v] * cost[v]; return;}
	mn[v] = cost[v]; sum[v] = 0;
	for (int u = Left[v]; u != 0; u = Right[u]) {DFS(u); mn[v] = min(mn[v], mn[u]); sum[v] += sum[u];}
	if (lim[v] > sum[v]) {res += (lim[v] - sum[v]) * mn[v]; sum[v] = lim[v];}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, rt;
	cin >> n;
	for (int i = 1, fa; i <= n; i++)
	{
		cin >> fa >> lim[i] >> cost[i];
		if (fa == -1) rt = i;
		else AddChild(fa, i);
	}
	DFS(rt);
	cout << res << endl;
	return 0;
}

