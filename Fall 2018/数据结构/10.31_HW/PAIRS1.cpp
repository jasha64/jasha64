//SPOJ - count the pairs
//����������������Ԫ�ض�Ӧ�Ĵ�ֻ��Ҫ����һ�ξͿ���ȫ���õ��ˣ���ʱ�临�Ӷ�O(nlogn) 
#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (k < 0) k = -k;
	else if (k == 0) {cout << 0 << endl; return 0;}
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a+n);
	int res = 0;
	for (int i = 0, j = 1; i < n; i++)
	{
		while (j < n && (long long)a[j] - a[i] < k) j++; //given all numbers are distinct
		if (j < n && (long long)a[j] - a[i] == k) res++;
		//������Ŀ�Լ������⣬��Ŀ˵everything can be done with 32-bit integers��ʵ��������int������ܳ���int��Χ 
	}
	cout << res << endl;
	
	return 0;
}

