#ifndef GUARD_Student_info
#define GUARD_Student_info

// `Student_info.h' header file
#include <iostream>
#include <string>
#include <vector>

class Student_info {
	//������ʶ������������˳����֣����ҿ��Գ��ֶ��
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;

public:
	Student_info();
	Student_info(std::istream&);
	std::string name() const {
		return n;
	}
	//������Ա���������Ըı�����������ִ�еĶ�����ڲ�״̬
	//�������ڳ�����Ա�����е��÷ǳ�����Ա��������Υ��������Ա�����Ķ���
	bool valid() const {
		return !homework.empty();
	}
	std::istream& read(std::istream&);
	double grade() const;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif

