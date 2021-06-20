//SPOJ - period
//KMP��ѭ���� 
#include <iostream>
using namespace std;

const int L = 1000001;
char s[L];
int len, Next[L];

void GetNext()
{
	int i = 0, k = -1;
	Next[0] = -1;
	while (i < len)
	{
		if (k == -1 || s[k] == s[i]) Next[++i] = ++k;
		else k = Next[k];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		cout << "Test case #" << kase << endl;
		cin >> len >> s;
		GetNext();
		for (int i = 2; i <= len; i++)
		{
			//ע�⣬�����i������Ϊi��ǰ׺���������һ���ַ��±�Ϊi��ǰ׺ 
			int l = i - Next[i];
			if (i % l == 0 && i != l) cout << i << ' ' << i / l << endl;
		}
		cout << endl;
	}
	
	return 0;
}
//�ⷨ�ο���https://www.cnblogs.com/chenxiwenruo/p/3546457.html
//��������S�ĳ���Ϊlen����S������Сѭ���ڣ�ѭ���ڵĳ���LΪlen-next[len]���Ӵ�ΪS[0��len-next[len]-1]��
//(1)���len���Ա�len-next[len]������������ַ���S������ȫ��ѭ����ѭ����ɣ�ѭ������T=len/L��
//(2)������ܣ�˵������Ҫ����Ӽ�����ĸ���ܲ�ȫ����Ҫ���ĸ�����ѭ������L-len%L������L=len-next[len]��(L-len%L=L-(len-L)%L=L-next[len]%L)
//
//����˵�ж�ѭ����Ҳ�����ù�ϣ���������ϣֵ�Ժ�ֱ��ö��ѭ���ڳ��Ȳ���һ���鼴�ɡ������ַ�����ʱ�临�Ӷ�
//�ǵ��ͼ�����͡�O(nlogn)�����������Ļ���������ÿ���Ӵ�����ֱ���һ�Σ�����TLE���ʴ��ֽⷨ���ԡ� 

