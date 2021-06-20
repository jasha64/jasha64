#include "Shape.h"
#include <iostream>
using std::istream;

Shape::Shape(const Shape& rhs) : sp(0)
{
	if (rhs.sp) sp = rhs.sp->clone();
	//���ƺ����Ķ�����δ��ʼ���ģ����Բ��������������
}
Shape& Shape::operator = (const Shape& rhs)
{
	if (&rhs != this) //���Ҹ�ֵ�ж�
	{
		delete sp; //�����������
		if (rhs.sp) sp = rhs.sp->clone();
		else sp = 0;
	}
	return *this;
}
istream& Shape::read(istream& input)
{
	delete sp;
	//ɾ��ԭ�е�����

	char c;
	input >> c;
	if (c == 'T') sp = new Triangle(input);
	else if (c == 'R') sp = new Rectangle(input);
	else sp = new Circle(input);

	return input;
}
