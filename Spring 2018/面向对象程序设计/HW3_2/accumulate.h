#pragma once
#include <vector>
template <class In, class X>
X accumulate(In b, In e, X x)
{
	while (b != e) x += *(b++);
	return x;
}
//��ģ��Ķ��������ϵͳ����ֱ�ӷ��ʵģ���˱��붨����ͷ�ļ���
