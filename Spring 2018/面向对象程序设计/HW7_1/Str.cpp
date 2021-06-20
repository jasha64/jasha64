#include "Str.h"
#include <iostream>
#include <cctype>
using std::istream; using std::ostream;

istream& operator >> (istream& input, Str& a)
{
	a.data.clear(); //Ĩȥa�����е�����

	char c;
	while (input.get(c) && isspace(c)) ; //����ǰ���ո�
	if (input)
	{
		do a.data.push_back(c);
		while (input.get(c) && !isspace(c)); //�����ַ���������
		if (input) input.unget(); //��������˺����ո񣬰����Ż���������
	}

	return input;
}
ostream& operator << (ostream& output, const Str& a)
{
	for (Str::size_type i = 0; i < a.size(); i++) output << a[i];
	return output;
}
Str operator + (const Str& a, const Str& b)
{
	Str r = a;
	r += b;
	return r;
}
