#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int N = 1001;
int n, m;
char A[N][N];
int Left[N][N], Up[N][N]; //Left: A[i][j]ͬһ���������ظ�����������±� 
int Max[N]; //Max: ���ڸ��������¶˵�(i, j)�����¶˵�(i, j-k)����Ӧ�����϶˵�����Ϊ(i-Max[k], j-k) 
long long Res;
 
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%s", A[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= 52; k++) //��Ϊ�ַ�һ��52�֣������Ӿ������52�С�52�� 
			{
				if (i - k > 0 && A[i - k][j] == A[i][j]) Up[i][j] = max(Up[i][j], i - k);
				if (j - k > 0 && A[i][j - k] == A[i][j]) Left[i][j] = max(Left[i][j], j - k);
			}
			Up[i][j] = max(Up[i][j], i - 52);
			Left[i][j] = max(Left[i][j], j - 52);
		}
	for (int j = 1; j <= m; j++)
	{
		memset(Max, 0, sizeof(Max));
		for (int i = 1; i <= n; i++)
		{
			int Now = 0;
			for (int k = 0; k < 52 && j - k > 0; k++)
			{
				Now = max(Now, Left[i][j - k]);
				if (Now == j - k) Max[k] = i;
				else {
					if (k) Max[k] = max(Max[k], Max[k - 1]);
					Max[k] = max(Max[k], Up[i][j - k]);
				}
				Res += i - Max[k];
			}
		}
	}
	
	cout << Res << endl;
	return 0;
}

