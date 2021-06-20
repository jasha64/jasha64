#include "median.h"
#include <vector>
#include <stdexcept>
#include <algorithm>
using std::vector;
using std::domain_error;
using std::sort;

double median(vector<double> vec)
{
	vector<double>::size_type siz = vec.size();
	if (siz == 0) throw domain_error("median of an empty vector");
	//�׳��쳣�������ڸú����ڴ�����Ϊ�������������������ʲô
	//��������£�����쳣�ش������õĳ����ɵ��ó����������Ǹ�Ϊ���ʵġ� 
	sort(vec.begin(), vec.end());
	if (siz % 2 == 0) return (vec[siz / 2] + vec[siz / 2 - 1]) / 2;
	else return vec[siz / 2];
}
