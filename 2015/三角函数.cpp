#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	char s;
	double angle, fx;
	
	while (true)
	{
		cout << "���������Ǻ������ͣ���s���������ң���c���������ң���t���������С����롰0���������򡣣���";
		cin >> s;
		switch (s)
		{
			case 's': cout << "����������ֵ��"; cin >> fx; angle = asin(fx);
						cout << "���ң�" << cos(angle) << ' ' << "���У�" << tan(angle) << endl; break;
			case 'c': cout << "����������ֵ��"; cin >> fx; angle = acos(fx);
						cout << "���ң�" << sin(angle) << ' ' << "���У�" << tan(angle) << endl; break;
			case 't': cout << "����������ֵ��"; cin >> fx; angle = atan(fx);
						cout << "���ң�" << sin(angle) << ' ' << "���ң�" << cos(angle) << endl; break;
			case '0': cout << "��лʹ�ã�" << endl; return 0;
			default: cout << "�������" << endl; break;
		}
	}
	return 0;
}

