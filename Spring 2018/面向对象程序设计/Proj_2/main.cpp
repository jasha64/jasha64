#include <iostream>
#include "largeint.h"
using std::cin; using std::cout; using std::endl;

int main()
{
	largeint a, b(10, 1); //���Թ��캯�� 
	
	cin >> a; //��������������� 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; //��������������
	cout << "-a = " << -a << endl;
	cout << "-b = " << -b << endl; //���Ը��� 
	
	if (a < b) cout << "a < b" << endl;
	else if (a == b) cout << "a = b" << endl; 
	else cout << "a > b" << endl;
	largeint abs_a = absv(a), abs_b = absv(b);
	if (abs_a != abs_b)
	{
		if (abs_a <= abs_b) cout << "|a| <= |b|" << endl;
		else if (abs_a >= abs_b) cout << "|a| >= |b|" << endl;
	}
	else cout << "|a| = |b|" << endl;
	//�������ֱȽ������ �� ����ֵ���� 
	
	system("pause");
	return 0;
}

