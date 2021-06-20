#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

std::istream& read_hw(std::istream&, std::vector<double>&);

class Core {
	friend class Student_info;

private:
	std::string n; //����
	virtual Core* clone() const { return new Core(*this); }
	//��Ա��������¡

protected:
	double midterm, final; //������ĩ����
	std::vector<double> homework; //��ͥ��ҵ����

	std::istream& read_common(std::istream& input) { input >> n >> midterm >> final; return input; }
	//��Ա����������Core��Grad�Ĺ�������
	//��Ա�����������ͥ��ҵ�ɼ�
public:
	Core() : midterm(0), final(0) {}
	Core(std::istream& input) { read(input); }
	//���캯��

	virtual ~Core() {}
	//����������������������

	std::string name() const { return n; } //����������������
	bool valid() const { return !homework.empty(); } //��Ա��������Core�����Ƿ���Ч
	std::istream& read(std::istream& input) { read_common(input); read_hw(input, homework); return input; }
	//��Ա����������һ��Core����
	virtual double grade() const; //��Ա�������ɼ����麯����
};
class Grad : public Core
{
public:
	Grad() : thesis(0) {}
	Grad(std::istream& input) { read(input); }
	//���캯��

	double grade() const { return std::min(Core::grade(), thesis); } //��Ա�������ɼ�
	std::istream& read(std::istream&);
	//��Ա����������һ��Grad����

private:
	double thesis; //���ķ���
	Grad* clone() const { return new Grad(*this); }
	//��Ա��������¡
};
class Student_info
{
private:
	Core * cp;

public:
	Student_info() : cp(0) {}
	Student_info(std::istream& input) { read(input); }
	//���캯��
	
	Student_info(const Student_info&);
	Student_info& operator = (const Student_info&);
	~Student_info() { delete cp; }
	//���ơ���ֵ����������

	std::istream& read(std::istream&);
	//��Ա����������

	std::string name() const
	{
		if (cp) return cp->name();
		else throw std::runtime_error("uninitialized Student");
	}
	double grade() const
	{
		if (cp) return cp->grade();
		else throw std::runtime_error("uninitialized Student");
	}
	//�������������������ɼ�

	static bool compare(const Student_info& a, const Student_info& b) { return a.name() < b.name(); }
	//��̬��Ա�������Ƚϣ������������ݣ�
};

bool compare(const Core&, const Core&);

