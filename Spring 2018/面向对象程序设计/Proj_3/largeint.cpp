#include "largeint.h"
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
using std::istream; using std::ostream;
using std::reverse;
using std::max;

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
	//ͳһ����

	largeint c;
	c.v.clear(); //�˴���c��������;��������Ҫһ����ȫδ��ʼ����largeint�������Զ���vector����ִ��clear����
	c.v.push_back(0); //��Ϊ�Ѿ�ͳһ���ţ����Է���λΪ+
	for (largeint::size_type i = 1, g = 0;; i++)
	{
		if (g == 0 && i >= a.v.size() && i >= b.v.size()) break;
		int x = g; //����һλ��λ������ֵ���ӵ���һλ
		if (i < a.v.size()) x += a[i];
		if (i < b.v.size()) x += b[i]; //������Ӧλ���
		c.v.push_back(x % largeint::BASE);
		g = x / largeint::BASE; //������һλ��λ
	}
	return c;
}
largeint operator - (const largeint& a, const largeint& b)
{
	if (a[0] && !b[0]) return -(-a + b);
	if (!a[0] &&  b[0]) return a + (-b);
	if (a[0]  &&  b[0]) return (-b) - (-a);
	//ͳһ����
	if (a < b) return -(b - a);
	//Ϊ��ʵ�ַ��㣬���ǲ�ȡ���ַ�ʽ��ȷ������a >= b

	largeint res; //���ڹ��캯����ԭ���Ѿ�����һλ��ֵΪ0����λ
	for (int i = 1; i < a.v.size(); i++)
	{
		res[i] += a[i]; //���������ĵ�ǰλ�ӵ�����ĵ�ǰλ
		if (i < b.v.size()) res[i] -= b[i]; //��ǰλ���
		if (res[i] < 0) { res[i] += largeint::BASE; res.v.push_back(-1); } //�����Ҫ��λ������һλ��ֵ��Ϊ-1
		else res.v.push_back(0); //������һλ��ֵΪ0
	}
	while (res.size() > 1 && res.v.back() == 0) res.v.pop_back(); //����ǰ��0
	return res;
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


