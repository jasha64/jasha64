#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>
const double pi = acos(-1);

class shape_base
{
	friend class Shape; //��������Ϊ��Ԫ�����������private��Ա��Ȩ��
public:
	shape_base() : area(0), circ(0) {}
	//���캯��

	virtual ~shape_base() {}
	//����������������������
	//�����Ҫɾ������ָ�����������Ļ���ָ�룬����Ҫ����һ������������������ȷ��������ռ���ȫ�ͷ�

	virtual void get_Area() = 0;
	virtual void get_Circ() = 0;
	//��Ա��������������������ܳ������麯����
	//���ڲ�֪����״���˴�����Ϊ���麯��������������ʱ��������
	//���������˴��麯�����˴�shape_base���Ϊ������࣬���ܴ���shape_base�����
	//���

	double Area() const { return area; }
	double Circ() const { return circ; }
	//������������������ܳ�

protected:
	double area, circ;
	//��Ա������������ܳ�

	virtual shape_base * clone() const = 0;
	//��Ա��������¡�����麯����
	//��Ϊ�����Ǹ�������࣬���ܶ������������Դ˺����޷������壬������Ϊ���麯��
};
class Triangle : public shape_base
{
public:
	Triangle() : a(0), b(0), c(0) {}
	Triangle(std::istream& input) { input >> a >> b >> c; }
	//���캯��

	void get_Area()
	{
		if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a - b >= c)
			throw std::domain_error("invalid side length"); //�������������Ҫ���׳��쳣
		get_Circ(); //�������Ҳ���׳��쳣���˴��˰��쳣�ش���ʹ���߽��д����ʴ˴���������
		double p = circ / 2;
		area = sqrt(p * (p - a) * (p - b) * (p - c));
	}
	void get_Circ()
	{
		if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a - b >= c)
			throw std::domain_error("invalid side length");
		circ = a + b + c;
	}
	//��Ա������������ܳ�

protected:
	Triangle * clone() const { return new Triangle(*this); }
	//��Ա��������¡
	//���������ػ��ຯ��ʱһ��Ҫ������б�ͷ���������ȫ��ͬ���������ຯ�����ص��ǻ���ָ��ʱӦ����������ָ�루��������Э�䣩

private:
	double a, b, c;
	//��Ա���������߱߳�
};
class Rectangle : public shape_base
{
public:
	Rectangle() : a(0), b(0) {}
	Rectangle(std::istream& input) { input >> a >> b; }
	//���캯��

	void get_Area()
	{
		if (a <= 0 || b <= 0) throw std::domain_error("invalid side length");
		area = a * b;
	}
	void get_Circ()
	{
		if (a <= 0 || b <= 0) throw std::domain_error("invalid side length");
		circ = 2 * (a + b);
	}
	//��Ա������������ܳ�

protected:
	Rectangle * clone() const { return new Rectangle(*this); }
	//��Ա��������¡

private:
	double a, b;
	//��Ա���������Ϳ�
};
class Circle : public shape_base
{
public:
	Circle() : r(0) {}
	Circle(std::istream& input) { input >> r; }
	//���캯��

	void get_Area()
	{
		if (r <= 0) throw std::domain_error("invalid side length");
		area = pi * r * r;
	}
	void get_Circ()
	{
		if (r <= 0) throw std::domain_error("invalid side length");
		circ = 2 * pi * r;
	}
	//��Ա������������ܳ�

protected:
	Circle * clone() const { return new Circle(*this); }
	//��Ա��������¡

private:
	double r;
	//��Ա�������뾶
};

//����࣬���������������Ӷ���ά�������Ե�ǰ����ʹ�ó����ܹ��Ը���shape_base�����������д���
class Shape
{
public:
	Shape() : sp(0) {}
	Shape(std::istream& input) : sp(0) { read(input);	}
	//���캯��

	Shape(const Shape&);
	Shape& operator = (const Shape&);
	~Shape() { delete sp; }
	//�漰�ռ���Դ������࣬��Ҫ���帴�ơ���ֵ����������
	
	std::istream& read(std::istream&);
	//��Ա����������

	void get_Area() const
	{
		if (sp) sp->get_Area();
		else throw std::runtime_error("uninitialized shape");
	}
	void get_Circ() const
	{
		if (sp) sp->get_Circ();
		else throw std::runtime_error("uninitialized shape");
	}
	//��Ա��������������������ܳ�

	double Area() const
	{
		if (sp) return sp->Area();
		else throw std::runtime_error("uninitialized shape");
	}
	double Circ() const
	{
		if (sp) return sp->Circ();
		else throw std::runtime_error("uninitialized shape");
	}
	//��Ա������������ܳ�
	//����shape_base���������ܳ��Ѿ�����Ϊ�麯�������Կ���ʵ�ֶ�̬��
	//ԭ���ϣ�����Ҫ�޸��ڲ�����ĳ�Ա������Ӧ�ü�const�޶������Ա����const������Ե���
private:
	shape_base * sp;
};
