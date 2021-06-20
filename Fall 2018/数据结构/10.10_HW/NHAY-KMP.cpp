//SPOJ - a needle in the haystack
//KMP(0.10s)
#include <cstdio>
#include <cctype>
using namespace std;

bool Read(char& c)
{
	c = getchar();
	while (!isalpha(c) && c != '\n') c = getchar();
	return c != '\n'; //��ֹԽ�������ж�����һ�ʲ��ʵ��������� 
}

int len;
int* Next;
char* p; //pattern
//������Ŀ��˵��p�����Ǹ��ǳ�������飬�ʲ��ò�����ȫ�ֱ��� 
void GetNext()
{
	int i = 0, k = -1;
	Next[0] = -1;
	while (i < len) //��Ϊ��Ҫ��ÿ�ҵ�һ��ƥ����ʱ��ִ��ʧ��������������ң����Դ˴���Next[]�Ķ������[0, len)��չ��[0, len] 
	{
		if (k == -1 || p[i] == p[k])
		{
			Next[++i] = ++k;
			if (p[i] == p[k]) Next[i] = Next[k];
		}
		else k = Next[k];
	}
}

int main()
{
	bool First = 1;
	while (scanf("%d", &len) == 1)
	{
		if (!First) printf("\n");
		else First = 0;
		
		p = new char [len+1];
		scanf("%s", p);
		Next = new int [len+1];
		GetNext();
		while (getchar() != '\n') ; //���˵��ڶ��к͵�����֮��Ļ��з� 
		
		//for (int i = 0; i <= len; i++) printf("%d ", Next[i]);
		//����ҵʱ�ǵ�ע�͵������ 
		
		char c;
		int i = 0, j = 0;
		while (true)
		{
			if (c == p[j])
			{
				if (++j == len)
				{
					printf("%d\n", i-len);
					j = Next[j];
				}
				i++;
				if (!Read(c)) break;
			}
			else if (Next[j] != -1) j = Next[j];
			else {
				i++;
				if (!Read(c)) break;
				j = 0;
			}
		}
		
		delete[] p;
	}
	
	return 0;
}

