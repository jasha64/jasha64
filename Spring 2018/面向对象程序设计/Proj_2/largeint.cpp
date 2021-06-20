#include "largeint.h"
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
using std::istream; using std::ostream;
using std::reverse;

largeint::largeint()
{
	v.push_back(0);
	v.push_back(0);
}
largeint::largeint(int n)
{
	if (n < 0) {v.push_back(1); n = -n;}
	else v.push_back(0);
	while (n > 0) {v.push_back(n % 10); n /= 10;}
}
largeint::largeint(size_type n, unsigned int val):v(n, val) //����������������ʼ��vector 
{
	v.push_back(0); //�ٽ�����λ�����ĩβ 
	reverse(v.begin(), v.end()); //���ת����vector��ʹ����λ����ǰ�沢ʹ�����������洢 
}

//�������ע��һ��ʵ�ַ�ʽ����Ϊ��Ԫ�������ǳ�Ա���������Բ�������largeint::operator>>����������ʵ�ֵĵط���friend���η�
istream& operator >> (istream& input, largeint& a)
{
	a.v.clear(); //������ڴ��е�ֵ 
	
	bool neg = 0; //�Ǹ��� 
	char c;
	while (input.get(c) && !isdigit(c) && c != '-') ; //���벢���������޹��ַ� 
	if (input)
	{
		if (c == '-') { neg = 1; input.get(c); } //�����˸��ţ����Ǹ���Ϊ������Ȼ�������һ���ַ� 
		do a.v.push_back(c - '0');
		while (input.get(c) && isdigit(c)); //�洢���е����� 
		if (input) input.unget(); //������滹�������������ݣ��ͰѶ��������ݷŻ��������� 
	}
	
	a.v.push_back(neg); //������λ�����ĩβ 
	reverse(a.v.begin(), a.v.end()); //���ת����vector��ʹ����λ����ǰ�沢ʹ�����������洢 
	while (a.size() > 1 && a[a.size()] == 0) a.v.pop_back(); //����ǰ��0
	//��ѧ���Ѿ��涨0��-0�ȼۣ������ڴ˶�-0��������
	return input;
}
ostream& operator << (ostream& output, const largeint& a)
{
	if (a[0] == 1) output << '-'; //����Ǹ����������������
	
	//��������vector�ڷ���洢���˴��������vector�д洢��ÿһλ 
	int siz = a.size();
	output << a[siz];
	for (int i = siz-1; i > 0; i--) output << a[i];
	
	return output;
}

bool operator < (const largeint& a, const largeint& b)
{
	if (a[0] == 1 && b[0] == 0) return true;
	if (a[0] == 0 && b[0] == 1) return false;
	if (a[0] == 1 && b[0] == 1) return -b < -a;
	//ͳһ���� 
	
	if (a.size() != b.size()) return a.size() < b.size(); //λ����ͬ����϶̵�����С
	for (int i = a.size(); i > 0; i--)
		if (a[i] != b[i]) return a[i] < b[i]; //λ����ͬ����λ�Ƚ� 
	return false; //��� 
}

largeint absv(const largeint& a)
{
	largeint b(a); //���Ƹ��� 
	b[0] = 0; //�޸ķ��� 
	return b; //���ظ��� 
}

