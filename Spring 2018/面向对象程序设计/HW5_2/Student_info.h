#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>

class Student_info
{
public:
	Student_info() :final_Grade(0), midterm(0), final(0) {}
	Student_info(std::istream& input) { Read(input); }
	std::istream& Read(std::istream&);
	std::ostream& Print(std::string::size_type, std::ostream&) const;
	//ԭ���ϣ����в�����ִ�ж����ڲ��ĳ�Ա������������const��Ա�������Ա�����͵ĳ����������
	std::string name() const { return n; }
	double final_grade() const { return final_Grade; }
	bool valid() const { return !homework.empty(); }
	double grade() const;
	void get_final_grade() { final_Grade = grade(); }
	bool fgrade() const { return final_grade() < 60; }
	std::string letters_grade() const;
private:
	std::vector<double> homework;
	std::string n;
	double final_Grade, midterm, final;
};
//���������ص�ȫ�ֺ���Ҳ�����ඨ���ͷ�ļ���
std::istream& Read(std::istream&, std::vector<double>&);
bool comp(const Student_info&, const Student_info&);
