//SPOJ - assembly line
//��Сֵ����ö��� 
//����˼·��NOIP2011�������ʼ�Աͦ�񣬿���̫��û�����ֶ��֣������� 
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return r;
}
const int N = 100001;
int n, sp[N], cost[N];
long long tot;
bool Check(const long long val)
{
	long long rem = tot;
	for (int i = 0; i < n; i++)
		if (val > sp[i] && (rem -= cost[i] * (val - sp[i])) < 0) return false; //ϸ�ģ�һ��ʼ��дval > sp[i]����һ�� 
	return true;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> tot;
		for (int i = 0; i < n; i++) {sp[i] = Read(); cost[i] = Read();}
		
		//�������͵Ķ��ֶ�����һ��ͷ�۵����⣺����Ӧ�õ���Low���ǵ���High��("off by 1 problem") 
		//����Сֵ�����������У���Ϊֻ��ҪMid��һ�����Ϣ��������һ�ֱȽϱ��յ�д�� 
		//���ǰ�[Low, High]�Ķ����"���Ž���������"�޸�Ϊ"���Ž���������"��ͬʱά��һ��Res��¼��ǰ�Ѿ���������Ž� 
		//��Ȼ���Ĵ𰸾���Res 
		long long Low = *min_element(sp, sp+n), High = 2e12, Res = Low;
		while (Low <= High)
		{
			long long Mid = (Low + High) / 2;
			if (Check(Mid)) {Res = Mid; Low = Mid + 1;}
			//�Ѿ���֤Mid���У��޸�Res = Mid���޸�Low = Mid+1�����Ž�ֻ���ܳ�����[Mid+1, High]) 
			else High = Mid - 1;
		}
		cout << Res << endl;
	}
	
	return 0;
}
//�ο����ϣ�https://ideone.com/wOLsFC 

