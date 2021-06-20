#include "Queue.h"
#include <iostream>
using std::ostream; using std::endl;

bool Queue::push(int d = 0)
{
	if (full()) return false;
	Node* nend = Newnode(d);
	if (empty()) begin = nend; //��������Ԫ���Ƕ���Ψһһ��Ԫ�أ����ʱbegin == NULL������Ҫ����beginָ��ָ�����Ԫ��
	else end->Next = nend;
	end = nend;
	cnt++;
	return true;
}
bool Queue::pop()
{
	if (empty()) return false;
	Node* nbegin = begin->Next;
	delete begin; begin = nbegin;
	cnt--;
	return true;
}
ostream& Queue::print(ostream& output) const
{
	for (Node* it = begin; it != NULL; it = it->Next) output << it->Data << ' '; //����NULL��ʾԽ��
	output << endl;
	return output;
}
