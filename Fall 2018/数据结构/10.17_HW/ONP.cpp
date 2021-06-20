//SPOJ - transform the expression
//ջ 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

inline int inp(char c) //priority in the stack
{
	switch (c)
	{
		case '$': return -1;
		case '(': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		default: return 3; //case '^'
	}
}
inline int exp(char c) //priority out of the stack
{
	switch (c)
	{
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		default: return 4; //case '^'
	}
}
//�ϰ�˵����ͨ��������Ҳ�趨���ȼ������ٷ������۵ĸ��ӳ̶ȣ�����������Ժϲ����� 
//��������д���ή�ͳ���ɶ��Բ���������Ѷȣ��˴�������� 

int main()
{
	//ios::sync_with_stdio(false);
	//һ��ʼ���ڼ�����䣬����һֱWA
	//�ٴ�ǿ���������Ҫ����������ͱ�׼����������ã���Ҫ�ر���ͬ�� 
	 
	int n;
	cin >> n;
	while (n--)
	{
		char c[401];
		cin >> c;
		int len = strlen(c);
		stack<char> s; s.push('$');
		for (int i = 0; i < len; i++)
		{
			if (isalpha(c[i])) putchar(c[i]); //������������ֱ����� 
			else if (c[i] == '(') s.push(c[i]); //���������ţ�ֱ����ջ 
			else if (c[i] == ')') //���������ţ�����һ���������Ժ���ջ�Ĳ��������γ�ջ�������Ȼ�������ų�ջ 
			{
				while (s.top() != '(') {putchar(s.top()); s.pop();}
				s.pop();
			}
			else { //�������Ƚ�ǰ�����и����ȼ���ͬ���ȼ����������γ�ջ�����Ȼ��ǰ��������ջ 
				while (exp(c[i]) <= inp(s.top())) {putchar(s.top()); s.pop();}
				s.push(c[i]);
			}
		}
		while (s.top() != '$') {putchar(s.top()); s.pop();}
		cout << endl;
	}
	
	return 0;
}

