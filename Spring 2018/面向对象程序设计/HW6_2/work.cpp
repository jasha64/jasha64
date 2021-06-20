#include <iostream>
#include <string>
#include "Queue.h"
#include "Work.h"
using std::cin; using std::cout; using std::endl;
using std::string;

const string spaces(20, ' ');

void Work()
{
	int icnt = 0, ocnt = 0;
	Queue<int> q;
	int tim = 0;
	cout << spaces << "ʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ�⣺" << endl;
	while (!q.isFull())
	{
		if (tim > 0 && tim % 25 == 0)
		{
			q.deQueue();
			cout << spaces << tim << "s����" << ++ocnt << "�˳��ӡ�" << endl;
		}
		if (tim % 8 == 0)
		{
			q.enQueue(tim);
			cout << tim << "s����" << ++icnt << "�˽��ӡ�" << endl;
		}
		tim++;
	}
	cout << spaces << "�ô����Ŷ������Ѵ�50�ˣ��������" << endl;
	cout << string(10, ' ') << "������Ա��" << q.front() << "s��ӡ�" << endl;
	cout << string(10, ' ') << "��β��Ա��" << q.back() << "s��ӡ�" << endl;

	cout << endl << endl;
	//��ֵ���������
	Queue<int> q1(q), q2;
	q1.output();
	q2 = q1;
	q2.output();
}
