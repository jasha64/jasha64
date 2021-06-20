//SPOJ - running median again
//�� 
//���ǿ���ͨ�����������»��ֳ��������������λ��������ת������������ֵ�����⣺ 
//��һ�������װ�����ǰһ�룬��a[0..(n+1)/2] 
//��һ��С����װ����ĺ�һ�룬��a[(n+1)/2+1..n-1] 
//������������λ������ֻ��Ҫȡ������ѵĸ����� 
//ע������ɾ��Ԫ��ʱά���������ѣ�ʹ�ô���ѵ���ֵʼ�����������м���� 
#include <cstdio>
#include <cctype>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

//ֵ��һ����ǣ�����������������δ֪�ģ����ܻ�ܴ�������Ҫ�Ӷ����Ż� 
//����ʵ�ϣ�ͨ���ر���ͬ�����������ǻ�TLE�ģ� 
inline int Read()
{
	int r = 0;
	bool isNeg = 0;
	char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') {isNeg = 1; c = getchar();}
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return isNeg ? -r : r;
}

int main()
{
	int T = Read();
	while (T--)
	{
		priority_queue<int> Front;
		priority_queue<int, vector<int>, greater<int> > Rear;
		int x;
		while ((x = Read()) != 0)
		{
			if (x == -1)
			{
				printf("%d\n", Front.top()); Front.pop();
				if (Front.size() < Rear.size()) {Front.push(Rear.top()); Rear.pop();}
				continue;
			}
			if (Front.empty()) {Front.push(x); continue;}
			int cmid = Front.top();
			if (x <= cmid)
			{
				Front.push(x);
				if (Front.size() > Rear.size() + 1) {Rear.push(Front.top()); Front.pop();}
			}
			else {
				Rear.push(x);
				if (Rear.size() > Front.size()) {Front.push(Rear.top()); Rear.pop();}
			}
		}
		printf("\n");
	}
	
	return 0;
}
//�ο�����: https://www.luogu.org/problemnew/solution/SP15376

