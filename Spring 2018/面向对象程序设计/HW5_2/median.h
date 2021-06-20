#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
//ģ�庯���Ķ���Ҫ����ϵͳ��ֱ�ӷ��ʵģ������䶨�����������ͷ�ļ���
template <class In, class X>
X median(In beg, In end, X val)
{
	if (beg == end) throw std::domain_error("median of an empty sequence");
	std::vector<X> vec;
	typename std::vector<X>::size_type siz = end - beg; //��ģ�����漰����Ա�����ģ������typenameǰ׺
	std::copy(beg, end, back_inserter(vec));
	//��[beg, end)��ֵ����һ�飬�Ӷ���֤������ԭ����
	std::sort(vec.begin(), vec.end());
	if (siz % 2 == 0) return (vec[siz / 2] + vec[siz / 2 - 1]) / 2;
	else return vec[siz / 2];
}
//�ٴ�ǿ��ͷ�ļ��в�����ʹ��using���������е����������������������namespace�޶���������ǣ��������ᱨĪ������Ĵ���
inline double median(const std::vector<double>& vec) { return median(vec.begin(), vec.end(), 0.0); }
