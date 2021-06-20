//POJ 2002 Squares
//hash 
//ǿ��Ǵ��POJ����C++98���ò���unordered_set�����ò���дһ��Hash 
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1001, MH = 999979; //��ϣ��Խ��Խ�����׳��ֳ�ͻ���˴�ѡ�ÿ���1e6��������Ϊģ�� 
struct Node
{
	int x, y, Next;
} pt[N]; //��̬�������ڵ��� 
int top = 1, x[N], y[N];
int Hash[MH];
inline int H(int x, int y) {return (x * x + y * y) % MH;} //�����ϣ�����������������˴���ȡƽ����+ȡ����Ϊ��ϣ���� 
//ֵ��һ����ǣ���Ŀ�Ѿ�˵��|x|, |y| < 20000����ʱ���ǿ��԰�(x, y)����20000������ 
//�����õ��Ĺ�ϣ��������ϣ��������˵�ǲ��ô����ͻ�� 
//Ȼ������ʵ�ʲ��ԣ�����д��WA�����ϳ�ͻ������TLE��˵�������˿������ֹ�ϣ������ź� 
inline void Insert(int x, int y)
{
	int h = H(x, y);
	pt[top].x = x; pt[top].y = y;
	pt[top].Next = Hash[h]; Hash[h] = top++;
}
bool Find(int x, int y)
{
	int h = H(x, y), cur = Hash[h];
	while (cur != 0)
	{
		if (pt[cur].x == x && pt[cur].y == y) return true;
		cur = pt[cur].Next;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n != 0)
	{
		memset(Hash, 0, sizeof(Hash)); top = 1; //��ʲ��ʳ�ʼ�� 
		for (int i = 0; i < n; i++) {cin >> x[i] >> y[i]; Insert(x[i], y[i]);}
		
		/*
		����˼·����Ϊ�����������Ժ�������Ϊ����������ε������������������ã� 
		�������ǲ�ȡ���������������е�����ϣ��O(n*n)ö�ٵ�ԣ���ÿ��ö�ٵ��� 
		��ԣ���ѯ���������Ƿ��ڹ�ϣ���С������ͰѼ�������ת�������������⡣��ʱ 
		�临�Ӷ�O(n*n) 
		*/
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
			{
				int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
				int x3, y3, x4, y4;
				int dx = -(y2 - y1), dy = x2 - x1;
				x3 = x1 + dx; y3 = y1 + dy;
				x4 = x2 + dx; y4 = y2 + dy;
				if (Find(x3, y3) && Find(x4, y4)) res++;
				x3 = x1 - dx; y3 = y1 - dy;
				x4 = x2 - dx; y4 = y2 - dy;
				if (Find(x3, y3) && Find(x4, y4)) res++;
			}
		
		res /= 4;
		cout << res << endl;
	}
	
	return 0;
}
//һ��ʼ�벻��������������һ�۱�ǩ��Ȼ�����ͨ����ϣֱֵ���ж������ε�����ͬ��������ˣ����� 
//�ο����ϣ�https://blog.csdn.net/alongela/article/details/8247605 

