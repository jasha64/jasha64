#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include "Student_info.h"
#include "grade.h"
using std::cin; using std::cout; using std::endl;
using std::setw; using std::setprecision; using std::streamsize;
using std::vector;
using std::string;
using std::max; using std::sort;
using std::domain_error;

int main()
{
	calc_fails();
	/*
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	//����ѧ�����ݣ����񲢴�����ܵ��쳣����ͳ��������ֳ��ȣ����ڶ������
	while (Read(cin, record))
	{
		try {
			get_final_grade(record);
			maxlen = max(maxlen, record.name.size());
			students.push_back(record);
		}
		catch (domain_error)
		{
			cout << record.name << " has done no homework" << endl;
		}
	}
	sort(students.begin(), students.end(), comp); //��ѧ����Ϣ�����ܳɼ�˳������

	//���ѧ���ɼ�ͳ�Ʊ�
	for (vector<Student_info>::size_type i = 0; i < students.size(); i++)
	{
		//���趨�Ŀ�����ѧ������
		cout << students[i].name << string(maxlen - students[i].name.size() + 1, ' ');
		//���ѧ���ɼ�
		streamsize prec = cout.precision();
		cout << setprecision(3) << students[i].final_grade << setprecision(prec);

		//������һ�����з�
		cout << endl;
	}
	*/
	//getchar();
	
	return 0;
}
