//SPOJ - ceiling function
//���Ľ�����ͬ���ж� 
//���Ľ���ֻ��Ҫ������Ŀ��˵�������������Ӷ�O(k*k), k<=20, ���ᳬʱ�� 
//����ͬ��������ͨ�����·��������жϣ�T1 == T2 ���ҽ��� T1��T2Ϊ�� ���� 
//T1����������T2��������ͬ������T1����������T2��������ͬ�������Ӷ�Ҳֻ��O(k)�� 
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int val;
	Node* ch[2];
	Node(int x = 0): val(x), ch{} {}
};
bool EqualShape(Node* a, Node* b)
{
	if (a == NULL || b == NULL) return a == NULL && b == NULL;
	return EqualShape(a -> ch[0], b -> ch[0]) && EqualShape(a -> ch[1], b -> ch[1]);
}
inline Node* Newnode(int x) {return new Node(x);}
struct Tree
{
	Node* Root;
	Tree(int k = 0): Root(NULL)
	{
		for (int i = 0, cur; i < k; i++)
		{
			cin >> cur;
			if (Root == NULL) {Root = Newnode(cur); continue;}
			Node* o = Root;
			while (true)
			{
				int d = cur > o -> val ? 1 : 0;
				if (o -> ch[d] == NULL) {o -> ch[d] = Newnode(cur); break;}
				else o = o -> ch[d];
			}
		}
	}
	friend bool operator == (const Tree& a, const Tree& b) {return EqualShape(a.Root, b.Root);}
};
vector<Tree> Table;

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		Table.clear();
		while (n--)
		{
			Tree T1(k);
			bool dup = 0;
			for (auto T2 : Table)
				if (T1 == T2) {dup = 1; break;}
			if (!dup) Table.push_back(T1);
			//����׼����unordered_set������أ������������Զ���������û��Ĭ�Ϲ�ϣ������ 
			//Ҳ����˵Ҫ�Լ�����һ����ϣ�������������Ĺ�ϣ���ڸ��ӣ������ 
		}
		cout << Table.size() << endl;
	}
	return 0;
}
//�ο����ϣ��������������� 
//����һ���鲻��������Ŀ�����û��������ۣ��ҿ��ܾ�Ҫ��������ֵķ�������ͬ���� 
//�ڴ˼�¼�ҵ�һ��˼·����ÿ���ڵ��ϵ�ֵ��ɢ������ͬһ��λ���ϵĽڵ��ֵһ����ȣ�
//Ȼ�󱣴�һ������ǰ��������������� ��Ϊ����ǰ��������������Ψһȷ����������
//�����ж��������Ƿ�ͬ��ֻ��Ҫ�ж����ǵ� ���ֱ�������Ƿ���ȼ���
//����������и��ķ������ӣ���ѡ��������и��ķ����� 

