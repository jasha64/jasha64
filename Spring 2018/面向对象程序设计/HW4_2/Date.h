#pragma once
//ȷ��ͷ�ļ������ظ����� 
#include <iostream>
const int max_Day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
	private: 
	//�ꡢ�¡��գ�����Ϊ˽�����ݳ�Ա 
	//class��Ĭ�ϱ�����ʽ��Ϊprivate������Ȼ������ʽ������������ʽ 
	int Y, M, D;
	
	public:
	Date();
	Date(int, int, int);
	Date(std::istream&);
	std::ostream& Display(std::ostream&); //ͷ�ļ��в�����ʹ��using����
	void inc_Year();
	void inc_Month();
	void inc_Day();
	
	//�������ӿڣ����������
	//ʹ��const�޶�����֤����ʱ�����޸�private����
	int Year() const { return Y; }
	int Month() const { return M; }
	int Day() const { return D; }
	
	//��Ա�����������ģ�������ʵ�ʵ����������md��max date����д�� 
	//���������������Ͷ��岻�ֿ�
	//���������2�£�M == 2��is_Leap_Year()��ֵ��Ϊ1����������Զ��޸�Ϊ29�죬��֮��Ȼ 
	int md() const { return max_Day[M] + (M == 2 * is_Leap_Year()); }
	
	//��Ա�����������ģ����жϸ����ڵ���/���Ƿ���Ч���������뺯�����׳��쳣�� 
	bool dayValid() const { return 0 < D && D <= md(); }
	bool monValid() const { return 1 <= M && M <= 12; }
	
	//��Ա�����������ģ����жϵ�ǰ������Ƿ�Ϊ���� 
	bool is_Leap_Year() const { return Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0); }
};

int Interval(Date, Date);
