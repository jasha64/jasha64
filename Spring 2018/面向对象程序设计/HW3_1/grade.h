#ifndef GUARD_grade_h
#define GUARD_grade_h
#include "Student_info.h"
//ȷ��ͷ�ļ�ֻ������һ��
double grade(const Student_info&);
inline double grade(double hw, double midterm, double final)
{
	return hw * 0.4 + midterm * 0.2 + final * 0.4;
}
//��������Ӧ�ö�����ͷ�ļ���
#endif
