#include <iostream>
#include "largeint.h"
using std::cout; using std::endl;

int main()
{
	largeint a, b(2147483647); //���Թ��캯�� 
	cout << a.size() << ' ' << b.size() << endl; //����size()���� 
	
	//system("pause");
	return 0;
}

