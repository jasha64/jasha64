//SPOJ - guess the queue
//��Ϊ�����е�Ԫ�ص�˳���ϵ�ǹ̶��ģ�ֻ��ͷβ��ı䣬��дһ������������ʵ�˫�˶��оͿ����� 
//����һ�ַ�������STL��deque��ͬʱ��map��ά����Ŷ�Ӧ��λ�� 
#include <iostream>
#include <map>
using namespace std;

map<int, int*> pos;
struct Deque
{
	int a[400001];
	int* f;
	int* b;
	Deque() {f = b = a+200000;} //[f, b)
	void push_back(int x) {*b = x; pos[x] = b; b--;}
	void pop_back() {pos.erase(*(++b));}
	void push_front(int x) {f++; *f = x; pos[x] = f;}
	void pop_front() {pos.erase(*(f--));}
	int get(int pos) {return *(f - pos + 1);}
	int find(int id) {return f - pos[id] + 1;}
};

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		int n;
		cin >> n;
		cout << "Case " << kase << ':' << endl;
		Deque dq;
		while (n--)
		{
			int typ;
			cin >> typ;
			if (typ == 1)
			{
				char op;
				int id;
				cin >> op >> id;
				if (op == 'B') dq.push_back(id);
				else dq.push_front(id);
			}
			else if (typ == 2)
			{
				char op;
				cin >> op;
				if (op == 'B') dq.pop_back();
				else dq.pop_front();
			}
			else {
				char op;
				int id;
				cin >> op >> id;
				if (op == 'D') cout << dq.get(id) << endl;
				else cout << dq.find(id) << endl;
			}
		}
	}
	
	return 0;
}

