#pragma once
#include <algorithm>
template <class In, class X>
X min_element(In b, In e)
{
	X x = *(b++);
	while (b != e) x = std::min(x, *(b++)); //ͷ�ļ��в�����ʹ��using����
	return x;
}
template <class In, class X>
X max_element(In b, In e)
{
	X x = *(b++);
	while (b != e) x = std::max(x, *(b++));
	return x;
}
//˳��ֻ������ input operator Ҫ�������֧��++��*��!=