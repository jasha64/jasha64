#pragma once
#include <iostream>

class Queue
{
public:
	Queue() :begin(NULL), end(NULL), cnt(0) {} //���캯��
	bool push(int); //����
	bool pop(); //����
	int& start() const { return begin->Data; } //���ʶ���Ԫ�أ���������ģ�
	int& back() const { return end->Data; } //���ʶ�βԪ�أ���������ģ�
	int count() const { return cnt; } //��ȡ�����е�Ԫ�ظ���
	bool empty() const { return begin == NULL; } //�ж϶����Ƿ�Ϊ��
	bool full() const { return cnt >= 50; } //�ж϶����Ƿ��������ﵽ50�˱�����
	std::ostream& print(std::ostream&) const; //�������
private:
	struct Node
	{
		int Data;
		Node *Next;
		Node(int d = 0) :Data(d), Next(NULL) {}
	} *begin, *end; //����ָ�롢��βָ�루����Խ��ָ�룬Խ��ָ��ֱ�ӽ���NULL��ʾ��
	inline Node* Newnode(int d = 0) { return new Node(d); }
	int cnt;
};
//����allocator��������������ڴ�ռ䣬���ⲻ����