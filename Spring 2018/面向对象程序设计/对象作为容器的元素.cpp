//δ���幹�캯���Ľṹ�������Ϊ������Ԫ�ر�����ʱ�����е��������������ǻ�õ���ʼ���� 
#include <iostream>
#include <vector>
using namespace std;

struct P
{
	int a, b;
};

int main()
{
	vector<P> v;
	
	v.resize(10);
	
	for (int i = 0; i < 10; i++) cout << '(' << v[i].a << ',' << v[i].b << ')' << ' ';
	cout << endl;
	
	return 0;
}

