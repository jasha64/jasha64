//orz vfk
#include <iostream>
#include <cstdio>
#include <set>
#include <iterator>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;

const int N = 100007;
int n, m, q, t, Spc;
double p;
bool First;
multiset<int, greater<int> > s; //һ��ʼ������set�����ظ� mdzz 

inline void Print(int a)
{
	if (!First) printf(" ");
	printf("%d", a);
	First = false;
}
void Work1()
{
	queue<int> qu;
	for (set<int>::iterator I = s.begin(); I != s.end(); I++) qu.push(*I);
	s.clear();
	while (!qu.empty()) {s.insert(qu.front() + q); qu.pop();}
}
void Work2() //����Ĳ��븴��ճ���� Ȼ��û�취 ������������������������������ 
{
	int delta = 0;
	
	First = true;
	for (int i = 1; i <= m; i++)
	{
		int a = *s.begin();
		int l = a + delta;
		s.erase(s.begin());
		if (i % t == 0) Print(l);
		int b = floor(l * p);
		int c = l - b;
		s.insert(b - delta - q); s.insert(c - delta - q);
		delta += q;
//		for (set<int>::iterator I = s.begin(); I != s.end(); I++) cout << (*I) + delta << ' '; cout << endl;
	}
	cout << endl;
	
	First = true;
	set<int>::iterator I = s.begin();
	for (int i = 1; I != s.end(); i++, I++)
		if (i % t == 0) Print((*I) + delta);
	cout << endl;
}

//�ǵ�ע�͵������ 
int main()
{
	freopen("earthworm.in", "r", stdin);
	freopen("earthworm.out", "w", stdout);
	
	int u, v;
	cin >> n >> m >> q >> u >> v >> t;
	p = u / (double)v;
	for (int i = 0, a; i < n; i++) {scanf("%d", &a); s.insert(a);}

	if (n == 1 || n == 1000 || m == 0) Spc = 0; //O((n + m) + (n + m + log(n + m)) * m)
	else if (q == 0) Spc = 1; //O((n + m) + mlog(n + m))
	else Spc = 2; //ͬ�� 
	
	if (Spc == 2) Work2();
	else {
		First = true;
		for (int i = 1; i <= m; i++) //O(m)
		{
			int a = *s.begin();
			s.erase(s.begin());
			if (i % t == 0) Print(a);
			int b = floor(a * p);
			int c = a - b;
			if (Spc == 0) Work1(); //O(n + m)
			s.insert(b); s.insert(c); //O(log(n + m))
	//		for (set<int>::iterator I = s.begin(); I != s.end(); I++) cout << *I << ' '; cout << endl;
		}
		cout << endl;
		
		First = true;
		set<int>::iterator I = s.begin();
		for (int i = 1; I != s.end(); i++, I++)
			if (i % t == 0) Print(*I); //O(n)
		cout << endl;
	}
	
	return 0; //ʱ���Ͻ�����1.471�ڴ�ѭ�� �ܹ������㼸���� ������дSplay���� 
}

