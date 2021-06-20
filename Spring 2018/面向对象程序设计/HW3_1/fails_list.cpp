#include <iostream>
#include <ios>
#include <iomanip>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
#include "grade.h"
#include "Student_info.h"

using std::cin; using std::cout; using std::endl; using std::streamsize;
using std::list;
using std::string;
using std::max;

//vector֧�������Ϳ���������ʣ�list֧�ֿ������������ɾ������ѡ����list������vector
list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator I = students.begin();
	//iterator����֧���޸ģ�const_iterator����֧�ֶ������ڶ����ֻ�����ʣ���֧�ֶԸö�������޸ģ���֧�ֶ�����������в�����ɾ��
	while (I != students.end())
	{
		if (fgrade(*I))
		{
			fail.push_back(*I);
			I = students.erase(I);
		}
		else I++;
	}
	return fail;
}
list<Student_info> students, fail;

void calc_fails()
{
	string::size_type len = 0; //Ҫ�ñ�׼���Դ��ĳ�����������ʾ��׼�����Ĵ�С
	Student_info s;
	while (Read(cin, s))
	{
		get_final_grade(s);
		students.push_back(s);
		len = max(len, s.name.size());
	}

	fail = extract_fails(students);
	streamsize prec = cout.precision();
	cout.precision(3);
	students.sort(comp);
	cout << "passing student records:" << endl;
	for (list<Student_info>::iterator I = students.begin(); I != students.end(); I++)
	{
		cout << I->name << string(len - (I->name).size() + 1, ' ') << I->final_grade << endl;
	}
	fail.sort(comp);
	cout << "failing student records:" << endl;
	for (list<Student_info>::iterator I = fail.begin(); I != fail.end(); I++)
		cout << I->name << string(len - (I->name).size() + 1, ' ') << I->final_grade << endl;
	cout.precision(prec); //�޸ľ��������Ϻ����Ҫ�ָ���Ĭ�ϵľ���
}
