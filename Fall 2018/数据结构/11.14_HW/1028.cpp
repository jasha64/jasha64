//10.131.235.233 - 1028
//����ؼ����ڰ��������Ĺ��̿���ÿ�������е���������һ����Ĺ��̣��ظ�n�Σ� 
//����ÿ���¼ӽ����ĵ㣬����Ҫͨ����֪����������Դ𰸵Ĺ��ף����ڵ����ĸ��ڵ�ľ��룬 
//�����˵�͵���k�����������һ���ֲ��ľ��� 
//���ѷ��֣�(d[i][k] + d[k][j] - d[i][j]) / 2�ǽڵ�k��lower(LCA(i, k), LCA(j, k))�ľ��룬 
//���������˵���͵���k��·��i-k��·��k-j�Ľ����ľ��� 
//�ɴ˿ɵã�ÿ�μ���һ����i�������Դ𰸵Ĺ��׵���min{(d[1][i] + d[j][i] - d[1][j]) / 2 | 1 < j < i} 
//�������Ǵ�ֻ�нڵ�1��2�ĳ�ʼ״̬����ʱ��Ϊd[1][2]�����ΰ����������ӵ㼴�� 
#include <iostream>
#include <climits>
using namespace std;

int d[31][31];

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		for (int i = 1; i <= n; i++)
			for (int j = i+1; j <= n; j++) cin >> d[i][j];
		
		int res = d[1][2];
		for (int i = 3; i <= n; i++)
		{
			int cur = INT_MAX;
			for (int j = 2; j < i; j++) cur = min(cur, (d[1][i] + d[j][i] - d[1][j]) / 2);
			res += cur;
		}
		
		cout << res << endl;
	}
	return 0;
}
//�ο����ϣ�https://blog.csdn.net/peter_819/article/details/51236389

