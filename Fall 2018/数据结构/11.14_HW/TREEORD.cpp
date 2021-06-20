//SPOJ - tree order
//�ݹ� 
//��Ϊ����ǰ������������������Ψһȷ������������̬���������ǴӸ�����ǰ������� 
//��������ָ������������ټ��������ĺ�������Ƿ�������ĺ��������ͬ���� 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 8001;
struct Node
{
	int id;
	Node* left;
	Node* right;
	Node(int x = 0): id(x), left(NULL), right(NULL) {}
} *Root;
int pre[N], in[N], post1[N];
//�����ľ��巽������Ϊǰ������ĵ�һ���ַ�һ���Ǹ�������������������ҳ������ڵ�λ�ã�
//��������������ֳ������֣����һ����Ϊ���������ұ�һ����Ϊ������������������������ 
//��������еĳ��Ⱥ���������еĳ�������ȵģ��ݴ˼����������������Ӧ������������� 
//���и�����һ�Σ��ݹ���м��� 
//����ǰ���������[l1, r1)�������������[l2, r2)���� 
Node* Build_Tree(int l1, int r1, int l2, int r2)
{
	if (l1 == r1) return NULL;
	Node* ret = new Node(pre[l1]);
	int pos = find(in + l2, in + r2, pre[l1]) - in, lslen = pos - l2;
	//�������ĸ�����������ж�Ӧ���±꣬���������������������ж�Ӧ�ĳ��� 
	ret -> left = Build_Tree(l1 + 1, l1 + 1 + lslen, l2, pos);
	ret -> right = Build_Tree(l1 + 1 + lslen, r1, pos + 1, r2);
	return ret;
}
int post2[N], Top = 0;
void Post_Order(Node* o)
{
	if (o -> left != NULL) Post_Order(o -> left);
	if (o -> right != NULL) Post_Order(o -> right);
	post2[Top++] = o -> id;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> pre[i];
	for (int i = 0; i < n; i++) cin >> post1[i];
	for (int i = 0; i < n; i++) cin >> in[i];
	
	Root = Build_Tree(0, n, 0, n);
	Post_Order(Root);
	cout << (memcmp(post1, post2, n * sizeof(int)) == 0 ? "yes" : "no") << endl;
	
	return 0;
}

