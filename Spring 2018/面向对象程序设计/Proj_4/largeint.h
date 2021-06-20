#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>

class largeint
{
public:
	typedef std::vector<int>::size_type size_type;
	//���Ͷ��� 

	largeint();
	largeint(int);
	largeint(size_type, unsigned int);
	//���캯�� 
	
	friend std::istream& operator >> (std::istream&, largeint&);
	friend std::ostream& operator << (std::ostream&, const largeint&);
	//������������������ 
	
	friend largeint operator + (const largeint&, const largeint&);
	largeint& operator += (const largeint& rhs) { *this = *this + rhs; return *this; }
	friend largeint operator - (const largeint&, const largeint&);
	largeint& operator -= (const largeint& rhs) { *this = *this - rhs; return *this; }
	friend largeint operator * (const largeint&, const largeint&);
	largeint& operator *= (const largeint& rhs) { *this = *this * rhs; return *this; }
	friend largeint operator / (const largeint&, const largeint&);
	largeint& operator /= (const largeint& rhs) { *this = *this / rhs; return *this; }
	friend int operator % (const largeint&, int);
	largeint& operator %= (int rhs) { *this = *this % rhs; return *this; }
	//���ؼӺš����š��˺š����š�ȡ����ż���Ӧ�ĸ��ϸ�ֵ�����

	friend bool operator < (const largeint&, const largeint&);
	friend bool operator > (const largeint& a, const largeint& b) { return b < a; }
	friend bool operator <= (const largeint& a, const largeint& b) { return !(b < a); }
	friend bool operator >= (const largeint& a, const largeint& b) { return !(a < b); }
	friend bool operator != (const largeint& a, const largeint& b) { return a < b || b < a; }
	friend bool operator == (const largeint& a, const largeint& b) { return !(a < b) && !(b < a); }
	//���ع�ϵ����� 
	
	friend largeint operator - (largeint a) { a[0] = !a[0]; return a; }
	friend largeint absv(const largeint&);
	//���ظ��� �� ����������ֵ 

	size_type size() const {return v.size() - 1;}
	//��Ա������λ��

private:
	static const int BASE = 10;
	//��̬���ݳ�Ա������

	std::vector<int> v;
	
	int& operator [] (int x) { return v[x]; }
	const int& operator [] (int x) const { return v[x]; }
	//�������������

	friend void Div10(largeint&);
	//��Ա����������10����������ǳ����������Լ��ļ���ר�õģ��༴��ĩλ��֤��0��
};
