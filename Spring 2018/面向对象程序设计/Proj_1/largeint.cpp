#include "largeint.h"

largeint::largeint()
{
	v.push_back(0); //����
	v.push_back(0); //����0
}
largeint::largeint(int n)
{
	//vector�Ǳ�׼�����ͣ��ᱻ����Ĺ��캯����ʼ�����˴�����Ҫ��Ϊ���Գ�ʼ�� 
	if (n < 0) {v.push_back(1); n = -n;}
	else v.push_back(0);
	while (n > 0) {v.push_back(n % 10); n /= 10;}
}

