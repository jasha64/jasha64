#pragma once
#include <iostream>
#include <cmath>
const double pi = acos(-1);

class Shape
{
public:
	Shape() : Area(0), Circ(0) {}
	//���캯��

	virtual double Area() = 0;
	//��Ա���������
	virtual double Circ() = 0;
	//��Ա�������ܳ�
	//���ڲ�֪����״���˴�����Ϊ���麯�������������������
protected:
	//���ֱ�����ǩ�µĳ�Ա������ࡢ��������ʣ�������ʹ���߷���
	double Area, Circ;
};
class Triangle : public Shape
//�����public�ؼ��ֵĺ����ǣ��ӻ���̳е�������������ӿڵ�һ���֣�����public��Ա�Զ���Ϊ������public��Ա
{
public:
	Triangle() : a(0), b(0), c(0) {}
	Triangle(std::istream& input) { input >> a >> b >> c; }
	//���캯��
	//�����������������û��๹�캯����ʼ������Ĳ��֣��ٵ��������๹�캯����ʼ��������Ĳ���

	double Area()
	{
		if (Shape::Area) return Shape::Area;
		double p = Circ() / 2;
		return Shape::Area = sqrt(p * (p - a) * (p - b) * (p - c));
	}
	//��Ա���������
	//���׹�ʽ

	double Circ()
	{
		if (Shape::Circ) return Shape::Circ;
		return Shape::Circ = a + b + c;
	}
	//��Ա�������ܳ�

private:
	double a, b, c;
	//��Ա���������߱߳�
};
class Rectangle : public Shape
{
public:
	Rectangle() : a(0), b(0) {}
	Rectangle(std::istream& input) { input >> a >> b; }
	//���캯��

	double Area()
	{
		if (Shape::Area) return Shape::Area;
		return Shape::Area = a * b;
	}
	//��Ա���������

	double Circ()
	{
		if (Shape::Circ) return Shape::Circ;
		return Shape::Circ = 2 * (a + b);
	}
	//��Ա�������ܳ�

private:
	double a, b;
	//��Ա���������Ϳ�
};
class Circle : public Shape
{
public:
	Circle() : r(0) {}
	Circle(std::istream& input) { input >> r; }
	//���캯��

	double Area()
	{
		if (Shape::Area) return Shape::Area;
		return Shape::Area = pi * r * r;
	}
	//��Ա���������

	double Circ()
	{
		if (Shape::Circ) return Shape::Circ;
		return Shape::Circ = 2 * pi * r;
	}
	//��Ա�������ܳ�

private:
	double r;
	//��Ա�������뾶
};
