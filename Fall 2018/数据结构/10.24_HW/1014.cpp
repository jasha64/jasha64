//10.131.235.233 - �º�ŵ�� 
//�ݹ���� 
//�����㷨��ʱ�临�Ӷ���O(2^n)����Ϊÿ���ƶ�һ������������2^n���ƶ��������Ż��Ժ�ȥ����ʱ����ʽ�����е�ָ������ӶȽ�������ʽ���� 
#include <iostream>
using namespace std;
//ifstream cin("1014.in");
//ofstream cout("1014.out"); //debug

int cur[46], tar[46];
long long cnt = 0;
inline int rem(int a, int b) {return 6 - a - b;}
inline bool AllSame(int id)
{
	for (int i = id; i > 1; i--)
		if (cur[i] != cur[1]) return false;
	return true;
}
void Move(int id, int dest) //��id�����Ƶ�dest��������Ҫ��1����id-1����ȫ�����Ƶ��м����ϣ� 
{
	if (cur[id] == dest) return;
	//�Ż��������ǰ�����Ŀ������Բ�̸�����ͬһ�������ϣ��򲻱ؼ������㣬ֱ�ӽ��𰸼���2^n-1 
	int d2 = rem(cur[id], dest);
	if (AllSame(id-1))
	{
		if (cur[1] != d2) //��Ϊ���ǲ���֤�������Ŀ�ĵغͳ�������ͬ������������ڴ˽������� 
		{
			cnt += (1ll << id-1) - 1;
			for (int i = id-1; i > 0; i--) cur[i] = d2;
		}
		//cout << "AllSame! " << (1ll << id-1) - 1 << endl;
	}
	else for (int i = id-1; i > 0; i--) Move(i, d2);
	//cout << cur[id] << " -> " << dest << endl;
	cnt++; cur[id] = dest;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 3; i++)
	{
		int k, c;
		cin >> k;
		while (k--) {cin >> c; cur[c] = i;}
	}
	for (int i = 1; i <= 3; i++)
	{
		int k, c;
		cin >> k;
		while (k--) {cin >> c; tar[c] = i;}
	}
	//for (int i = 1; i <= n; i++) cin >> cur[i];
	//for (int i = 1; i <= n; i++) cin >> tar[i]; //debug
	for (int i = n; i > 0; i--) Move(i, tar[i]);
	cout << cnt << endl;
	return 0;
}
//һ��ʼ�Լ���Ƶĵݹ��㷨��Wrong Answer�������� 
//�ο����ϣ�https://www.cnblogs.com/SoulSecret/p/8046901.html 

