#include <iostream>
#include <stdexcept>
#include "Date.h"
using std::istream; using std::ostream; using std::endl;
using std::domain_error;

//���ֹ��캯�����������ԣ����캯��Ҳ����������
Date::Date() { Y = 2015; M = D = 1; }
//�˴���ȫ����ʼ��Ϊ0�����Ǹ�ֵΪһ����Ч�����ڡ�
//���������Ա������ȷ����������Ч�ԵĲ��֣����ǾͿ���ȷ��һ�������д��ڵ�һ��Date���Ͷ�������Ч���ڡ�
Date::Date(int a, int b, int c): Y(a), M(b), D(c) {} //���캯����ʼ���б��ڹ��캯���ĺ�����֮ǰִ��
Date::Date(istream& input)
{
	input >> Y >> M >> D;
	if (!dayValid()) throw domain_error("invalid day");
	if (!monValid()) throw domain_error("invalid month");
}

//��Ա��������� 
//�˴���Ҫ�ر�ע����ǣ�Date::Ӧ���ڷ���ֵ���ͺ󡢺�����ǰ
ostream& Date::Display(ostream& output)
{
	output << Y << "��" << M << "��" << D << "��" << endl; //������Date������ꡢ�¡��գ��м��õ�����������һ�����з�
	return output;
}

//��Ա����������1�꣬����1�£�����1�� 
void Date::inc_Year()
{
	if (is_Leap_Year() && M == 2 && D == 29) D = 28; //����2��29������һ��Ľ������Ϊƽ��2��28�� 
	Y++;
}
void Date::inc_Month()
{
	if (++M == 13) { Y++; M = 1; }
	if (D > md()) D = md(); //�������һ���º�����ڳ����˵����������ڣ���������Ϊ���ڵ����������� 
}
void Date::inc_Day()
{
	if (++D > md())
	{
		D = 1;
		if (++M == 13) { Y++; M = 1; } //12��31������һ��Ľ������Ϊ����1��1�� 
	}
}

//���ܺ���������һ����������һ��/�������ӵ����������ڼ������ڼ������ֱ�ӷ���Դ�ļ��У����ܱ������û����ã�
//����һ�꺯���У���Ҫ�ر�ע��������ǣ������ǰ���´��ڶ��£������ʱ�����ǿ���˴�����¶����ǵ�����£�����Ҫ�жϴ����Ƿ������� 
//�������ǿ���˵�����¶����Ǵ�����£���Ҫ�жϵ����Ƿ������� 
//���⣺2��29������һ��ֻ�����ӵ�2��28�գ��۳�����
int ymd(Date d)
{
	bool is_229 = d.is_Leap_Year() && d.Month() == 2 && d.Day() == 29;
	if (d.Month() > 2) d.inc_Year();
	return 365 - is_229 + d.is_Leap_Year();
}
//����һ�º����У���Ҫע����������ǰ���������¸����д���������ڣ�����Ҫ�۳����������
int mmd(Date d)
{
	int re = d.md(), dd = d.Day();
	d.inc_Month();
	if (dd > d.Day()) re -= dd - d.Day();
	return re;
}

//���ܺ����������������ڵļ������Ϊ����������ƽ�ȹ�ϵ�����Բ���Ϊ����һ�����ڵĳ�Ա�������ã� 
int Interval(Date a, Date b)
{
	int A = 0, B = 0; //A��¼����a�����˶����죬B��¼����b�����˶�����
	while (a.Day() >= 28) { A++; a.inc_Day(); }
	while (b.Day() >= 28) { B++; b.inc_Day(); }
	//�������д���һ��bug��
	//�����Ҫ����һ���£������¸���û��������ڣ�������⣬���԰���ĩ��������ǰ�����¸��³���
	//ͬ������Ҳ���Խ������2��29������һ������⡣
	while (a.Month() < b.Month()) { A += a.md(); a.inc_Month(); }
	while (b.Month() < a.Month()) { B += b.md(); b.inc_Month(); }
	while (a.Day() < b.Day()) { A++; a.inc_Day(); }
	while (b.Day() < a.Day()) { B++; b.inc_Day(); }
	while (a.Year() < b.Year()) { A += ymd(a); a.inc_Year(); }
	while (b.Year() < a.Year()) { B += ymd(b); b.inc_Year(); }
	return abs(A-B); //����һ����ͬ�����ڣ�a��b���ӵ������Ĳ�ľ���ֵ������a��b�������������
}

