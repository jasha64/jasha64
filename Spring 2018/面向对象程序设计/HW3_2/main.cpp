#include <iostream>
#include "accumulate.h"
#include "minmax.h"
#include "output.h"
#include <cstdlib>
#include <string>

using std::string;
using std::cout; using std::endl;

const int N = 10;
int a[N];
double b[N];
string c[N];

int main()
{
	srand(19260817); //��ʼ�����������
	for (int i = 0; i < N; i++) a[i] = rand(); //����[0, RAND_MAX]��Χ�ڵ�int�����
	for (int i = 0; i < N; i++) b[i] = rand() / (double)RAND_MAX; //����[0, 1]��Χ�ڣ�double���͵������
	for (int i = 0; i < N; i++)
	{
		int st = rand() / (double)RAND_MAX * 25; //ָ������ַ���������ĸ��[0, 25]
		int len = rand() / (double)RAND_MAX * 24 + 1; //����ַ����ĳ��ȣ�[1, 25]
		c[i].resize(len);
		for (int j = 0; j < len; j++) c[i][j] = 'a' + (st + j) % 26;
	} //��������ġ�ֻ��Сд��ĸ��ɵ�string

	cout << "the integer list: "; output(a, a + N);
	cout << "the sum of the integer list: " << accumulate(a, a + N, 0) << endl;
	cout << "the max element in the integer list: " << max_element<int*, int>(a, a + N) << endl;
	cout << "the min element in the integer list: " << min_element<int*, int>(a, a + N) << endl;
	//���ڲ����в��漰���������е�class X�����ϵͳ�޷��Զ��ж�XΪint��������ǵ���ʱ������ʽ������X����int����

	cout << "the double list: "; output(b, b + N);
	cout << "the sum of the double list: " << accumulate(b, b + N, 0.0) << endl;
	cout << "the max element in the double list: " << max_element<double*, double>(b, b + N) << endl;
	cout << "the min element in the double list: " << min_element<double*, double>(b, b + N) << endl;

	cout << "the string list: "; output(c, c + N);
	cout << "the concatenation of the string list: " << accumulate(c, c + N, string()) << endl;
	//������������ע��std::string���캯�����÷�
	//string()��string(0, ' ')����һ���յ��ַ�����string(0)���൱�ڸ�string��ֵ0���ǷǷ���
	//��Ȼ�����ֱ�ӽ�����������д��""�����ᱻĬ����Ϊ��char*���ͣ����벻ͨ��
	cout << "the max string in the string list: " << max_element<string*, string>(c, c + N) << endl;
	cout << "the min string in the string list: " << min_element<string*, string>(c, c + N) << endl;

	//getchar();
	return 0;
}
