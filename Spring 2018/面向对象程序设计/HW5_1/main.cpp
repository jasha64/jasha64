#include "Queue.h"
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;

const string spaces(20, ' ');

int main()
{
	int icnt = 0, ocnt = 0; //������������ѳ�������������������������ã�
	Queue q;
	int tim = 0; //��ǰʱ��
	cout << spaces << "ʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ�⣺" << endl;
	while (!q.full())
	{
		if (tim > 0 && tim % 25 == 0)
		{
			q.pop();
			cout << spaces << tim << "s����" << ++ocnt << "�˳��ӡ�" << endl;
		}
		//ÿ25s����һ��
		if (tim % 8 == 0)
		{
			q.push(tim); //�ڶ����м�¼��������˽��ӵ�ʱ�̣��������յ����
			cout << tim << "s����" << ++icnt << "�˽��ӡ�" << endl;
		}
		//ÿ8s����һ��
		//��ִ�г��Ӻ�ִ�н��ӣ��Ա�֤������ֶ�����;�ﵽ50�˵�ִ����whileѭ���󲻵�50�˵���ϵͳ������⵽��Ա�����
		tim++;
	}
	cout << spaces << "�ô����Ŷ������Ѵ�50�ˣ��������" << endl;
	cout << string(10, ' ') << "������Ա��" << q.start() << "s��ӡ�" << endl;
	cout << string(10, ' ') << "��β��Ա��" << q.back() << "s��ӡ�" << endl;

	system("pause");
	return 0;
}
