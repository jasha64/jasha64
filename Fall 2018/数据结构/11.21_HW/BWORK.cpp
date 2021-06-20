//SPOJ - boring homework
//ģ�� 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//�������Ľڵ� 
extern struct Node* const null; //��"extern"�ؼ��ְ�����null�ڵ�������ᵽ��������ǰ��, ������Ĭ�Ϲ��캯���м�������null 
struct Node
{
	int val;
	int siz, l, r; //�����Ĵ�С���������Ĵ�С���������Ĵ�С 
	int ll, lr, rl, rr; //���������������Ĵ�С, ���������������Ĵ�С, ��������(��ͼ��) 
	Node* ch[2];
	Node(int val = 0, int siz = 1): val(val), siz(siz), l(0), r(0), ll(0), lr(0), rl(0), rr(0), ch{null, null}
	{
		//cout << "Construction function called, val = " << val << ", siz = " << siz << endl;
		//�������б�ʱ���캯���Ĳ�����ṹ��Ĳ���������������ʱ�����������������ָ�����Ǻ����������ǽṹ����� 
	}
	void Maintain()
	{
		ll = ch[0] -> l; lr = ch[0] -> r;
		rl = ch[1] -> l; rr = ch[1] -> r;
		l = ch[0] -> siz; r = ch[1] -> siz; siz = l + r + 1;
	}
} *Root;
Node* const null = new Node(0, 0); 

inline Node* Newnode(int v) {return new Node(v);}
//curh��ʾ��ǰ�ݹ���ȣ��ݹ������ά����h��ʾ���������ȣ������ʱ�� 
int curh, h; //�ѵ�ǰ��Ⱥ���������Ϊȫ�ֱ�����������Insert�����оͲ��ط������� 
void Insert(Node*& o, int val)
{
	h = max(h, curh);
	if (o == null) {o = Newnode(val); return;}
	//��Ŀ��֤�������val == o->val��������ʴ˴����迼�� 
	int d = o -> val > val ? 0 : 1;
	++curh; Insert(o -> ch[d], val); --curh;
	o -> Maintain();
}
//�ѵ�ַpos���n���ַ�ȫ����ֵΪc 
inline void Print(char* pos, int n, char c) {for (int i = 0; i < n; i++) pos[i] = c;}

//����һ����ʶ������ǰ���DFS�򣬵����������һ�����⣺һ�е�����������һ�εó��� 
//Ϊ���ܹ�����޸�������ݣ�����ѡ�����������ݴ浽��ά�ַ������У���������Ҳ����������ʱȥ����ĩ����ո� 
//��Ȼ������BFS����ʶ���������������һ�����һ�е�������Ӷ��Ϳ���ֱ������ˡ��������ƣ��˴����ԡ� 
const int W = 158;
char out[159][W]; //��Ϊÿ�εݹ���ÿ��ܷ��ʵ�out���κ�һ��λ�ã�����������ȫ�ֱ��� 
//˵���л����������һ��ʼ������159*79������WA���ѿ�ĳ�ԭ���������Ժ��AC�� 
//��Ȼ��֪��Ϊʲô��ȿ��ܴﵽN�Ķ�������������ʾ���ǣ����鿪С��Ҳ�������WA 

//��(row, col)Ϊ���Ͻǣ�������oΪ�������� 
void DrawTree(Node* o, int row, int col)
{
	if (o == null) return;
	
	//������ǰ�ڵ㣬�����ֲ�����·������ߣ�����У� 
	int lb = col, lp = col + o->ll, mid = col + o->l, rp = col + o->l + 1 + o->rl;
		//��߽������У���ֲ�������У����ڵ������У��ҷֲ�������� 
	if (o -> ch[0] != null)
	{
		Print(&out[row][lb], o -> ll, ' '); Print(&out[row+1][lb], o -> ll, ' ');
		out[row][lp] = '+'; out[row+1][lp] = '|';
		Print(&out[row][lp+1], o -> lr, '-'); Print(&out[row+1][lp+1], o -> ll, ' ');
	}
	out[row][mid] = 'o';
	if (o -> ch[1] != null)
	{
		Print(&out[row][mid+1], o -> rl, '-'); Print(&out[row+1][mid+1], o -> ll, ' ');
		out[row][rp] = '+'; out[row+1][rp] = '|';
		Print(&out[row][rp+1], o -> rr, ' '); Print(&out[row+1][rp+1], o -> rr, ' ');
	}
	
	//�ݹ黭������ 
	if (o -> ch[0] != null) DrawTree(o -> ch[0], row + 2, lb);
	if (o -> ch[1] != null) DrawTree(o -> ch[1], row + 2, mid + 1);
}

void RemoveTree(Node* o)
{
	if (o == null) return;
	RemoveTree(o -> ch[0]); RemoveTree(o -> ch[1]); delete o;
}

int main()
{
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		Root = null; h = 0;
		int n;
		cin >> n;
		for (int i = 0, c; i < n; i++) {cin >> c; Insert(Root, c);}
		h = 2 * h + 1; //ͼ�����߶ȵ������������ȵĶ���+1����0��ʼ��ţ� 
		
		printf("Case #%d:\n", kase);
		fill(out[0], out[0] + h*W, ' ');
		DrawTree(Root, 0, 0);
		//ȥ����ĩ����ո� 
		for (int i = 0; i < h; i++)
			for (int j = W-1; j >= 0; j--)
				if (out[i][j] == ' ') out[i][j] = 0;
				else break;
		for (int i = 0; i < h; i++) printf("%s\n", out[i]);
		
		RemoveTree(Root);
	}
	
	return 0;
}

