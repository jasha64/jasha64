//��ʽ�����Ѷ������´���elearning��ҵ�ǵÿ��������ͼƬ
#include <iostream>
#include <stdexcept>
#include "Date.h"
using std::cin; using std::cout; using std::endl;
using std::domain_error;

int main()
{
	Date d1, d2;
	
	cout << "�������������ڣ������գ��Կո�ָ�����" << endl;
	try { d1 = Date(cin); d2 = Date(cin); }
	catch (domain_error e)
	{
		cout << e.what() << endl;
		//system("pause");
		return 1;
	}
	cout << "����һ��"; d1.Display(cout);
	cout << "���ڶ���"; d2.Display(cout);
	cout << "���������������Ϊ��" << Interval(d1, d2) << endl;

	Date d = d1;
	d.inc_Day(); cout << "������һ����һ��Ϊ��"; d.Display(cout);
	d = d1;
	d.inc_Month(); cout << "������һ����һ��Ϊ��"; d.Display(cout);
	d = d1;
	d.inc_Year(); cout << "������һ����һ��Ϊ��"; d.Display(cout);
	
	//system("pause");
	//�˴�ֱ��ʹ��getchar()����ʹ������ͣ���Ա�ǰ���εĳ����֣�ֻ��������EOF����ʱ�ſ���ʹ��getchar()
	//�Ʋ�����Ϊ������ִ�е����ʱ���뻺�������ǿյġ�
	//ִ��cin.clear()��Ч����Ϊcin.clear()��������������Ĵ���״̬��������������뻺������
	//ִ��cin.ignore(2147483647, '\n')�����ʹ��getchar()��ͣ����
	//����cin.sync()�͹ر���ͬ������VS����Ч����Dev����Ч���Ʋ�������������ʵ�ֺͱ������йء�
	//Ϊ��������ʹ��system("pause")����

	return 0;
}

