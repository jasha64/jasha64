#pragma once
//ȷ��ͷ�ļ�ֻ������һ��
#include "Vec.h"
#include <algorithm>
#include <vector>
#include <cstring>

class Str
{
public:
	typedef Vec<char>::size_type size_type;
	//���Ͷ���

	Str() {}
	Str(size_type n, char c = 0) :data(n, c) {}
	Str(const char* c) { std::copy(c, c + strlen(c), std::back_inserter(data)); }
	template <class In> Str(In b, In e) { std::copy(b, e, std::back_inserter(data)); }
	//���캯��

	size_type size() const { return data.size(); }
	//��Ա����������

	char& operator [] (int i) { return data[i]; }
	const char& operator [] (int i) const { return data[i]; }
	//�������������

	friend std::istream& operator >> (std::istream&, Str&);
	friend std::ostream& operator << (std::ostream&, const Str&);
	//������������������
	//��Ϊ������������ֱ�ӷ���private��Ա�����Բ���������Ԫ����
	//���￼�ǵ�������������������һ������࣬������Ȼ������������Ԫ��˰

	Str operator += (const Str& rhs)
	{
		copy(rhs.data.begin(), rhs.data.end(), std::back_inserter(data));
		return *this;
	}
	//���ظ��ϸ�ֵ��+=
private:
	Vec<char> data;
};
//�ṹ�嶨������Ӧ����ֺŽ���
Str operator + (const Str&, const Str&);
//�������������
//ͷ�ļ��в�Ӧ������ִ������
//��Ϊ����Ҫ����private��Ա�����Բ���Ҫ��������Ԫ����