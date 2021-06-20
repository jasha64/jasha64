#pragma once
#include <cstddef>
#include <iostream>

template <class T>
class Queue
{
public:
	typedef std::ptrdiff_t size_type; //���Ͷ���

	Queue() :head(NULL), rear(NULL), siz(0)
	{
		std::cout << "default constructor called." << std::endl; //���ո�ʽҪ�����������ʾ���
	} //default constructor
	Queue(const Queue& q)
	{
		std::cout << "copy constructor called." << std::endl;
		copyLink(q.head);
	} //copy constructor
	~Queue()
	{
		std::cout << "destructor called." << std::endl;
		freeLink();
	} //destructor
	Queue& operator= (const Queue&); //assignment operator

	bool enQueue(T);	//����
	bool deQueue();		//����

	T front() const { return head->val; } //���ض���Ԫ�ص�ֵ 
	T back() const { return rear->val; } //���ض�βԪ�ص�ֵ 

	size_type size() const { return siz; } //��С

	bool isEmpty(void) const { return head == NULL; } //�ж϶����Ƿ�Ϊ�� 
	bool isFull(void) const { return size() >= 50; } //�ж϶����Ƿ�����

	void output(void) const; //������� 

private:
	struct node{
		T val;
		node* next;
		node(T v = T()) :val(v), next(NULL) {}
	}*head, *rear; //������βԪ��ָ�� 
	size_type siz;

	//�ڴ������ 
	void copyLink(node *);	//������������ 
	void freeLink(); //�ͷ�����������ռ�ռ� 
};

template <class T>
Queue<T>& Queue<T>::operator= (const Queue& rhs)
{
	std::cout << "operator=() called." << std::endl;
	if (&rhs == this) return *this; //��ֹ���Ҹ�ֵ
	freeLink();
	copyLink(rhs.head);
	return *this;
}
template <class T>
bool Queue<T>::enQueue(T val)
{
	if (isFull()) return false;
	node* new_rear = new node(val);
	if (isEmpty()) head = new_rear;
	else rear->next = new_rear;
	rear = new_rear;
	siz++;
	return true;
}
template <class T>
bool Queue<T>::deQueue()
{
	if (isEmpty()) return false;
	node* new_head = head->next;
	delete head; head = new_head;
	siz--;
	return true;
}
template <class T>
void Queue<T>::output() const
{
	int cnt = 0; //��ǰ���Ѿ�����˶��ٸ�Ԫ�أ�ÿ10����һ��
	for (node* it = head; it != NULL; it = it->next)
	{
		std::cout << it->val << ' '; ++cnt;
		if (cnt == 10) { std::cout << std::endl; cnt = 0; }
	}
	std::cout << std::endl;
}
template <class T>
void Queue<T>::copyLink(node* rhs)
{
	//�������ռ䲢����ֵ
	head = new node(rhs->val);
	const node* ci = rhs->next;
	node* i = head;
	while (ci != NULL)
	{
		i->next = new node(ci->val);
		i = i->next; ci = ci->next;
	}
	rear = i;
}
template <class T>
void Queue<T>::freeLink()
{
	//����ͷ����뵽�Ŀռ�
	node* i = head;
	while (i != NULL)
	{
		node* j = i->next;
		delete i;
		i = j;
	}
	head = rear = NULL;
}

