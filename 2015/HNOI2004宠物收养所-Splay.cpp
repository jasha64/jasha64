#include <iostream>
#include <cstdlib>
using namespace std;
  
const int N = 80007, MOD = 1000000;
struct Node *P, *null;
struct Node
{
    int v, s;
    Node* ch[2];
      
    Node(int v = 0):v(v) {ch[0] = ch[1] = null; s = 1;}
    int cmp(int k) const
    {
        int d = k - ch[0] -> s;
        if (d == 1) return -1;
        else return d <= 0 ? 0 : 1;
    }
    void Maintain() {s = ch[0] -> s + ch[1] -> s + 1;}
      
    void* operator new (size_t) {return P++;} //*��̬�ڴ������������new������ӿ��ٶ� 
} a[N];
Node* Root;
int v, Cache;
  
void Rotate(Node* &o, int d) //BST��ת 
{
    Node* k = o -> ch[d ^ 1]; o -> ch[d ^ 1] = k -> ch[d]; k -> ch[d] = o;
    o -> Maintain(); k -> Maintain(); o = k;
}
void Splay(Node* &o, int k) //�ҳ����е�kСԪ�أ�����ת���� 
{
    int d = o -> cmp(k);
    if (d == 1) k -= o -> ch[0] -> s + 1;
    if (d != -1)
    {
        Node* p = o -> ch[d];
        int d2 = p -> cmp(k);
        int k2 = d2 ? k - p -> ch[0] -> s - 1 : k;
        if (d2 != -1)
        {
            Splay(p -> ch[d2], k2);
            if (d == d2) Rotate(o, d ^ 1); else Rotate(o -> ch[d], d);
        }
        Rotate(o, d ^ 1);
    }
}
void Fit() //*��Ŀ��Ҫ 
{
    Cache = 2147483647;
    int d;
    Node* o = Root;
      
    while (o != null)
    {
        Cache = min(Cache, abs(o -> v - v));
        if (o -> ch[0] != null) Cache = min(Cache, abs(o -> ch[0] -> v - v));
        if (o -> ch[1] != null) Cache = min(Cache, abs(o -> ch[1] -> v - v));
        if (o -> v == v) {Cache = 0; return;}
        else {d = o -> v > v ? 0 : 1; o = o -> ch[d];}
    }
}
int Find() //����ֵ��Ӧ������ 
{
    int r = 0, d;
    Node* o = Root;
      
    while (o != null)
    {
        d = v < o -> v ? 0 : 1;
        if (d) r += o -> ch[0] -> s + 1;
        if (o -> v == v) return r;
        o = o -> ch[d];
    }
      
    return 0;
}
Node* Merge_(Node* Left, Node* Right) //Left����Ԫ��С��Right����Ԫ��ʱ��O(n)ֱ�Ӻϲ� 
{
    Splay(Left, Left -> s);
    Left -> ch[1] = Right;
    Left -> Maintain();
    return Left; 
}
void Split(Node* o, int k, Node* &Left, Node* &Right) //���������k��Ԫ�ط��ѳ��� 
{
    Splay(o, k);
    Right = o -> ch[1];
    o -> ch[1] = null;
    o -> Maintain();
    Left = o;
}
void Insert(Node* &o) //���� 
{
    if (Root == null) {Root = new Node(v); return;}
      
    int k;
    Fit(); v -= Cache;
    k = Find();
    if (!k) {v = v + (Cache << 1); k = Find() - 1; v -= Cache;}
    else v += Cache;
    Node *c1 = null, *c2 = o;
      
    if (k) Split(o, k, c1, c2);
    o = new Node(v); o -> ch[0] = c1; o -> ch[1] = c2;
}
Node* Merge(Node* Left, Node* Right) //O(nlogn)����ʽ�ϲ� 
{
    if (Left && !Right) return Left;
    if (Right && !Left) return Right;
    if (Left -> s > Right -> s) return Merge(Right, Left);
      
    while (Left != null)
    {
        Splay(Left, 1);
        v = Left -> v; Left = Left -> ch[1];
        Insert(Right);
    }
      
    return Right;
}
void Remove() //ɾ��Ԫ�� 
{
    int k = Find();
    Node *l, *r;
      
    Splay(Root, k);
    l = Root -> ch[0]; r = Root -> ch[1];
    //    delete Root;
    Root = l == null ? r : Merge_(l, r);
}
  
int main()
{
    int q, c, Res = 0;
    bool p = false;
      
    ios::sync_with_stdio(false);
    P = a;
    null = new Node(); null -> s = 0; Root = null;
      
    cin >> q;
    while (q--)
    {
        cin >> c >> v;
        if (Root == null) {Insert(Root); p = c;}
        else if (c ^ p)
        {
            Fit(); v -= Cache;
            if (Find()) Remove();
            else {v = v + (Cache << 1); Remove();}
            Res = (Res + Cache) % MOD;
        }
        else Insert(Root);
    }
      
    cout << Res << endl;
      
    return 0;
}

