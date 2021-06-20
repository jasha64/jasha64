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
	
	friend bool operator < (const largeint&, const largeint&);
	friend bool operator > (const largeint& a, const largeint& b) { return b < a; }
	friend bool operator <= (const largeint& a, const largeint& b) { return !(b < a); }
	friend bool operator >= (const largeint& a, const largeint& b) { return !(a < b); }
	friend bool operator != (const largeint& a, const largeint& b) { return a < b || b < a; }
	friend bool operator == (const largeint& a, const largeint& b) { return !(a < b) && !(b < a); }
	//���ع�ϵ����� 
	
	friend largeint operator - (largeint a) { a[0] = !a[0]; return a; }
	//friend largeint absv(const largeint& a) {return a < 0 ? -a : a;} ����д���򵥵�����
	friend largeint absv(const largeint&);
	//���ظ��� �� ����������ֵ 
	//��Ԫ�������ǳ�Ա�����Գ�Ա�����ķ���Ȩ�ޣ���Ϊ����ֵ������Ҫ����largeint���˽�г�Ա�����ǰ�����������Ԫ���� 
	//���ظ��ź���д����Ԫ������ԭ���ǣ�����Ψһ�������������Ҳ����������Բ���д�ɳ�Ա����

	size_type size() const {return v.size() - 1;}
	//��Ա������λ��
private:
	std::vector<int> v;
	
	int& operator [] (int x) { return v[x]; }
	const int& operator [] (int x) const { return v[x]; }
	//�������������
	//�˴�Ϊ��Ա�����������������������ǲ�ϣ�������û�����Ȩ�޵������ʴ�����ĳһλ����������Ϊprivate 
};
