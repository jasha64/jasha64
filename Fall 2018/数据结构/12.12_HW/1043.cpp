//10.131.235.233 1043 zoo
//ƽ������AVL��ʵ��Ӧ���кܲ����ã���Ϊ���ⲻ�漰�ϲ��ͷ��ѣ�����ѡ�ýϼ򵥵�Treap�� 
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

extern struct Node* const null;
struct Node
{
	int val, key, siz;
	Node* ch[2];
	
	Node(int v = 1, int s = 1): val(v), key(rand()), siz(s), ch{null, null} {}
	int cmp(int rhs) const
	{
		if (val == rhs) return -1;
		return rhs > val ? 1 : 0;
	}
	void Maintain() {siz = ch[0]->siz + ch[1]->siz + 1;}
};
Node* const null = new Node(0, 0);
Node* Root = null;
//C++�ж���ȫ�ֱ����ĳ�ʼ��˳���޹涨��null��������ʱ��δ���壬����֮ǰ����ֵ��Ϊ��0��externĬ��ֵ�� 
//���������Root = null�������Ƶ�21�У�Root�ᱻ��ʼ��Ϊ0x0������̨ʽ���ı��뻷���£� 
void Rotate(Node*& o, int d)
{
	Node* k = o -> ch[d^1]; o -> ch[d^1] = k -> ch[d]; k -> ch[d] = o;
	o -> Maintain(); k -> Maintain(); o = k;
}
void Insert(Node*& o, int x)
{
	if (o == null) {o = new Node(x); return;}
	int d = x < o -> val ? 0 : 1; //������ͬ�ڵ�ʱ����ʹ��cmp���� 
	Insert(o -> ch[d], x);
	if (o -> ch[d] -> key > o -> key) Rotate(o, d ^ 1);
	o -> Maintain();
}
void Remove(Node*& o, int v)
{
	int d = o -> cmp(v);
	if (d == -1)
	{
		Node* u = o;
		if (o -> ch[0] == null) {o = o -> ch[1]; delete u;}
		else if (o -> ch[1] == null) {o = o -> ch[0]; delete u;}
		else {
			int d2 = o -> ch[0] -> key > o -> ch[1] -> key ? 1 : 0;
			Rotate(o, d2); Remove(o -> ch[d2], v);
		}
	}
	else Remove(o -> ch[d], v);
	if (o != null) o -> Maintain();
}
int Kth(Node* o, int k)
{
	if (o == null || k <= 0 || k > o -> siz) return 0;
	int lsiz = o -> ch[0] -> siz;
	if (lsiz + 1 == k) return o -> val;
	else if (k <= lsiz) return Kth(o -> ch[0], k);
	else return Kth(o -> ch[1], k - lsiz - 1);
}
long long val[100001];
struct Query
{
	int l, r, k, no;
	friend bool operator < (const Query& a, const Query& b)
	{
		if (a.l != b.l) return a.l < b.l;
		return a.r < b.r;
	}
} q[50001];
int out[50001];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 0; i < m; i++) {cin >> q[i].l >> q[i].r >> q[i].k; q[i].no = i;}
	
	sort(q, q+m);
	for (int ll = 1, rr = 0, i = 0; i < m; i++) //��ǰƽ����Ϊ�����е�����[ll, rr]�������� 
	{
		while (rr < q[i].r) Insert(Root, val[++rr]); 
		while (ll < q[i].l) Remove(Root, val[ll++]);
		out[q[i].no] = Kth(Root, q[i].k);
	}
	
	for (int i = 0; i < m; i++) cout << out[i] << endl;
	return 0;
}

