#pragma once
#include <iostream>
//��һ�������[b, e)��Χ�ڵ����ж����ÿո��������ĩû�ж���ո񣩣������
template <class In>
void output(In b, In e)
{
	std::cout << *(b++);
	while (b != e) std::cout << ' ' << *(b++);
	std::cout << std::endl;
}
