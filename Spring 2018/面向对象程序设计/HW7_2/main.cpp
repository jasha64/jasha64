#include <iostream>
#include "Shape.h"
using std::cin; using std::cout; using std::endl;

int main()
{
	cout << "�����������ε������߳���";
	Triangle t(cin);
	cout << "�����ε��ܳ�Ϊ��" << t.Circ() << "�����Ϊ��" << t.Area() << endl;

	cout << "��������εĳ��Ϳ�";
	Rectangle r(cin);
	cout << "���ε��ܳ�Ϊ��" << r.Circ() << "�����Ϊ��" << r.Area() << endl;

	cout << "������Բ�İ뾶��";
	Circle c(cin);
	cout << "Բ���ܳ�Ϊ��" << c.Circ() << "�����Ϊ��" << c.Area() << endl;

	system("pause");
	return 0;
}
