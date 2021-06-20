#include <iostream>
#include <vector>
#include <string>
#include "Student_info.h"
#include "grade.h"
//ֵ��һ����ǣ���ͷ�ļ��а���cpp�ļ��ǲ��淶�ģ����׵����ظ����� 
using std::istream;
using std::vector;
using std::string;

istream& Read(istream& input, vector<double>& vec)
{
	if (input)
	{
		vec.clear(); //��ʼ��
		double x;
		while (input >> x) vec.push_back(x); //�������ݲ��洢��vec��
		input.clear(); //������������״̬
	}
	return input;
}
istream& Read(istream& input, Student_info& s)
{
	input >> s.name >> s.midterm >> s.final;
	Read(input, s.homework);
	return input;
}
bool comp(const Student_info& a, const Student_info& b)
{
	return a.final_grade > b.final_grade;
}
void get_final_grade(Student_info& s)
{
	s.final_grade = grade(s);
}
