#pragma once
#include <vector>

class largeint
{
public:
	typedef std::vector<int>::size_type size_type;
	//���Ͷ���

	largeint();
	largeint(int n);
	//���캯��

	size_type size() const {return v.size() - 1;}
	//���������������ĳ���ض����ݽṹ�Ĵ�С��ʱ��Ӧʹ�ø����ݽṹ����Ӧ����
	//ԭ���ϣ�����Ҫ�޸�������ڲ����ݵĳ�Ա������Ӧ��const�޶������Ա����const������Ե��� 
	
private:
	std::vector<int> v;
	//��vector����������ĸ���λ�����е�һλΪ����λ��0��ʾ�Ǹ���1��ʾ���� 
	//�ڶ�λ��ʼ�����򱣴�����������ڶ�λΪ��λ������λΪʮλ���������ƣ� 
};

