//10.131.235.233 - ���򼯺� 
//�ݹ���� 
#include <iostream>
using namespace std;

int n;
bool fir = 1;
void Solve(int cur, int k) //���{cur, cur+1, ..., n}�ĵ�kС���Ӽ� 
{
	if (k == 1) return; //��С���Ӽ����ռ� 
	int b = 1 + (1 << n-cur); //���k>b�������û��cur����Ϊֻ�еڶ�С����bС���Ӽ��а���cur 
	if (k > b) Solve(cur+1, k-b+1); //��ѡcur �����ѡcur��������Ӽ���{cur+1, ..., n}�ĵ�(k-b+1)С���Ӽ� 
	else { //ѡcur 
		if (fir) fir = 0;
		else printf(" ");
		printf("%d", cur);
		Solve(cur+1, k-1); //���ѡ��cur��������Ӽ������ಿ����{cur+1, ..., n}�ĵ�(k-1)С���Ӽ� 
	}
}

int main()
{
	int k;
	cin >> n >> k;
	
	Solve(1, k);
	if (fir) printf("0");
	printf("\n");
	return 0;
}

