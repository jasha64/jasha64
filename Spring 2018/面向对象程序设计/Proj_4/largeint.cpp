#include "largeint.h"
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iterator>
using std::istream; using std::ostream;
using std::reverse;
using std::max;
using std::copy;
using std::back_inserter;

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
largeint::largeint(size_type n, unsigned int val) :v(n, val)
{
	v.push_back(0);
	reverse(v.begin(), v.end());
}

istream& operator >> (istream& input, largeint& a)
{
	a.v.clear();
	
	bool neg = 0;
	char c;
	while (input.get(c) && !isdigit(c) && c != '-') ;
	if (input)
	{
		if (c == '-') { neg = 1; input.get(c); }
		do a.v.push_back(c - '0');
		while (input.get(c) && isdigit(c));
		if (input) input.unget();
	}
	
	a.v.push_back(neg);
	reverse(a.v.begin(), a.v.end());
	while (a.size() > 1 && a[a.size()] == 0) a.v.pop_back();
	return input;
}
ostream& operator << (ostream& output, const largeint& a)
{
	if (a[0] == 1) output << '-';
	
	int siz = a.size();
	output << a[siz];
	for (int i = siz-1; i > 0; i--) output << a[i];
	
	return output;
}

largeint operator + (const largeint& a, const largeint& b)
{
	if (a[0] && !b[0]) return b - (-a);
	if (!a[0] && b[0]) return a - (-b);
	if (a[0] && b[0]) return -(-a + (-b));

	largeint c;
	c.v.clear();
	c.v.push_back(0);
	for (largeint::size_type i = 1, g = 0;; i++)
	{
		if (g == 0 && i >= a.v.size() && i >= b.v.size()) break;
		int x = g;
		if (i < a.v.size()) x += a[i];
		if (i < b.v.size()) x += b[i];
		c.v.push_back(x % largeint::BASE);
		g = x / largeint::BASE;
	}
	return c;
}
largeint operator - (const largeint& a, const largeint& b)
{
	if (a[0] && !b[0]) return -(-a + b);
	if (!a[0] &&  b[0]) return a + (-b);
	if (a[0]  &&  b[0]) return (-b) - (-a);
	if (a < b) return -(b - a);

	largeint res;
	for (largeint::size_type i = 1; i < a.v.size(); i++)
	{
		res[i] += a[i];
		if (i < b.v.size()) res[i] -= b[i];
		if (res[i] < 0) { res[i] += largeint::BASE; res.v.push_back(-1); } 
		else res.v.push_back(0);
	}
	while (res.size() > 1 && res.v.back() == 0) res.v.pop_back();
	return res;
}
largeint operator * (const largeint& a, const largeint& b)
{
	largeint res; //���ڹ��캯����ԭ���Ѿ�����һλ��ֵΪ0����λ
	if (a[0] ^ b[0]) res[0] = 1; //�������

	res.v.resize(a.v.size() + b.size() - 1);
	//�˷����������ÿһλ��Ҫ���Ӷ�Σ��������������㿪ʼǰֱ��resize�趨�ó�ʼλ���������Ͳ����ڹ�����push_back����������������
	for (largeint::size_type i = 1; i < a.v.size(); i++)
	{
		int c = 0;
		for (largeint::size_type j = 1; j < b.v.size(); j++)
		{
			res[i + j - 1] += c + a[i] * b[j]; //���Ķ�Ӧλ����������ǰ��λ�˷��������һλ�Ľ�λ
			c = res[i + j - 1] / largeint::BASE; res[i + j - 1] %= largeint::BASE; //�����λ
			if (j == b.v.size() - 1 && c)
				if (i + j < res.v.size()) res[i + j] += c; 
				else res.v.push_back(c); //���һλ��λ���⴦��
		}
	}
	while (res.size() > 1 && res.v.back() == 0) res.v.pop_back(); //����ǰ��0
	return res;
}
//������˼·���������Ʊ�������ķ���
largeint operator / (const largeint& a, const largeint& b)
{
	largeint res;
	if (a[0] ^ b[0]) res[0] = 1; //�������

	largeint c1 = absv(a), c2 = absv(b);
	while (c2 * 10 < c1) { c2 *= 10; res.v.push_back(0); } //�����̵�λ�������������Լ��ļ�����λ����Ӧ����
	for (largeint::size_type i = res.v.size()-1; i > 0; i--)
	{
		while (c1 - c2 > 0) { c1 -= c2; res[i]++;} //�����̵ĵ�ǰλ
		if (i > 1) Div10(c2); //��������10�������̵���һλ���������Ҫ�����ĩλ��֤��0���������Ǵ˴�����֮ǰ�����ж���
	}
	return res;
}
int operator % (const largeint& a, int b)
{
	int res = 0;
	for (largeint::size_type i = a.v.size()-1; i > 0; i--)
		res = (res * largeint::BASE + a[i]) % b; //��λ����ȡģ����
	return a[0] ? -res : res; //�������
}

bool operator < (const largeint& a, const largeint& b)
{
	if (a[0] == 1 && b[0] == 0) return true;
	if (a[0] == 0 && b[0] == 1) return false;
	if (a[0] == 1 && b[0] == 1) return -b < -a;
	
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = a.size(); i > 0; i--)
		if (a[i] != b[i]) return a[i] < b[i];
	return false;
}

largeint absv(const largeint& a)
{
	largeint b(a);
	b[0] = 0;
	return b;
}
//����10˼·������λ�������༴������λ��ʮλ���ϵĲ��ֱַ��Ƴ�����������ԭ����
void Div10(largeint& a)
{
	largeint c;
	c.v.clear();
	c.v.push_back(a[0]);
	copy(a.v.begin() + 2, a.v.end(), back_inserter(c.v));
	a = c;
}

