#include <stdio.h>

int main()
{
	int i;
	char c;
	float x;
	//scanf���������־: ���հ����ַ�; �Ѷ������ָ�����ַ���; �������һ���ַ����ܲ��빹����ȷ�����ݸ�ʽ 
	scanf("%d%c%f", &i, &c, &x);
	//input: 123a123x.45
	printf("%d %c %f\n", i, c, x);	
	//output: 123 a 123.000000
	return 0;
}

