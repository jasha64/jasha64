#include <iostream>
using namespace std;

int main()
{
	//�ַ�������Բ�ָ����С����ʱ�Գ�ʼ�����ַ�������+1Ϊ��С 
	char c[] = "HoHoHo";
	cout << sizeof(c) << endl;
	
	char *p = c;
	p[0] = 'P'; p[1] = 'e';
	cout << p << endl;
	
	//���԰��ַ�����ֵ��ָ�����������ֵ��pָ��Ĳ�����c[0]�ĵ�ַ�����ǳ����洢����һ���µ�ַ 
	p = "T110";
	//p[0] = 'Z'; //ȡ��ע�ͻᵼ��RE���ַ������������޸� 
	cout << p << endl;
	
	return 0;
}

