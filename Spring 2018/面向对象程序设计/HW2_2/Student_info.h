#pragma once
#include <iostream>
#include <vector>
#include <string>

struct Student_info
{
	std::vector<double> homework;
	std::string name;
	double final_grade, midterm, final;
};
//������ʹ��usingָ���Ϊ���ʹ���ˣ�����Ҳ��԰������ͷ�ļ��ĳ������ͬ�����޶������ǲ��Ϲ淶�� 
//���ڵ�����Щ����������Ľṹ��������أ���˽����Ƿ�װ��һ��ͷ�ļ���
std::istream& Read(std::istream&, Student_info&);
std::istream& Read(std::istream&, std::vector<double>&);
bool comp(const Student_info&, const Student_info&);
void get_final_grade(Student_info&);
//ͷ�ļ��е����ݶ��Ƕ����Ժ�˵���Եģ������п�ִ������ 
