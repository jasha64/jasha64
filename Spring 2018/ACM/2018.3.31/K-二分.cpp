//���ȷ�������һ�����ɣ�˵��ǰ�����ǿ��ͶƱ���������˵���������ǿ��ͶƱ��
//Ȼ���֣�����˵��ǿ��ͶƱ���˱�࣬���õ���Ʊ���������ӡ������ʹ�ö��ַ��� 
//���ִ𰸣���ǰ����ö��ÿһ���ˣ������ǰ����˵�ai���ڵ�ǰͶƱ��������������ǿ��ͶƱ�� 
#include <iostream>
using namespace std;

const int N = 200007;
int a[N], n, m;

bool Can(int x)
{
	int Cur = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= Cur) ++Cur;
		else if (x > 0) {--x; ++Cur;}
		if (Cur >= m) return 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int Low = 0, High = m, Res; //[Low, High]�ĺ����޸�Ϊ���ܳ��ָ��Ŵ𰸵����� 
	while (Low <= High)
	{
		int Mid = (Low + High) / 2;
		if (Can(Mid)) {Res = Mid; High = Mid - 1;}
		else Low = Mid + 1;
	}
	
	cout << Res << endl;
	
	return 0;
}

