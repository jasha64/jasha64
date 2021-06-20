//SPOJ - gallantry
//̰�� 
//������ս�������飬����ѡ�˵ķ�ʽһ���ǴӸ����ͣ�������Ȼ��i�ֻ�ѡ��(2i-1)��͵�2i�� 
//һ�����öԷ���ѡ��ζ������ս�����Ĳ�ֵ�������2������һ������ѡ�ֵĲ�ֵ��������һ����û�к�Ч�� 
//���ԣ��ڲ�ֵ������С��ʱ���öԷ���ѡ�������Ų��ԣ������͵õ���̰���㷨 
#include <iostream>
#include <algorithm>
using namespace std;

int a[10001], b[5001];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a+n);
	for (int i = 0; i < n; i += 2) b[i/2] = a[i+1] - a[i];
	int m = n/2;
	sort(b, b+m);
	int d = 0;
	for (int i = 0; i < m; i++) d += b[i];
	if (d <= 0) {cout << -1 << endl; return 0;}
	int p = 0;
	do {
		d -= b[p];
		d -= b[p];
		p++;
	} while (d > 0 && p < m);
	if (p >= m && d > 0) cout << m << endl;
	else cout << p-1 << endl;
	return 0;
}

