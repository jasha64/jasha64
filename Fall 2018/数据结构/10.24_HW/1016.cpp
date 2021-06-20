//10.131.235.233 - �绰���� 
//���仯�������Ǽ򵥱��ѵ��Ż�����ʱ�临�Ӷ�O(n*l) 
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, f[101];
string t, p[101];
int len;
inline char idx(char c)
{
	switch (c)
	{
		case 'a': case 'b': case 'c': return '1';
		case 'd': case 'e': case 'f': return '2';
		case 'g': case 'h': case 'i': return '3';
		case 'j': case 'k': case 'l': return '4';
		case 'm': case 'n': return '5';
		case 'o': case 'p': case 'q': return '6';
		case 'r': case 's': case 't': return '7';
		case 'u': case 'v': case 'w': return '8';
		default: return '9'; //case 'x' 'y' 'z' 
	}
}
bool Streql(int cur, int i) //���봮��curλ����p[i]������ͬ���Ӵ�����p[i]ƥ���� 
{
	int lp = p[i].size();
	if (cur + lp > len) return 0;
	for (int j = 0; j < lp; j++)
		if (idx(p[i][j]) != t[cur + j]) return 0;
	return 1;
}
bool Search(int cur) //��ʾ��ǰ���ڽ������봮��[cur, len)λ 
{
	if (f[cur] != -1) return f[cur];
	for (int i = 0; i < n; i++)
		if (Streql(cur, i) && Search(cur + p[i].size())) return f[cur] = 1;
	return f[cur] = 0;
}

int main()
{
	cin >> n >> t; len = t.size();
	for (int i = 0; i < n; i++) cin >> p[i];
	
	memset(f, -1, sizeof(f)); f[len] = 1;
	if (Search(0)) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
//���ݷ���ʱ�临�Ӷ����Ծ�ȷ��������������һ�����Զ�������������:  
//���ݷ���Ӧ�÷�Χ�ܹ㣬ֻҪ�ܰѴ���������ֳɲ�̫��Ĳ��裬ÿ��������ֻ�в� 
//̫���ѡ�񣬶����Կ���Ӧ�û��ݷ���Ϊʲô˵"��̫��"�أ�����һ�ð���L�㣬ÿ��ķ� 
//֧���Ӿ�Ϊb�Ľ�������������ߴ�1 + b + b^2 + ... + b^(L-1) = (b^L - 1) / (b-1)��
//������b̫����L̫�󣬽����������һ���������֡�
//��������� ���㷨�������ž���(��2��)�� 

