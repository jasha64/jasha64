//SPOJ TETRIS2D ���� 
//����Ҫ����O(n)���Ӷ�����ɣ��������Ǳ������һ���㷨������������һ�з���Ĳ���
//����ɾ��->������������Ŀ���ɾ�����ԣ���ʹ��ɾ�������ʱ�临�ӶȽ���O(n) 
//�콫ÿһ�ж�����һ����������ÿ�����ͷ
#include <iostream>
#include <vector>
using namespace std;

const int B[7][4][4][2] =
{
	{
		{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
		{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {0, 3}}
	},
	{
		{{0, 0}, {0, 1}, {1, 0}, {2, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
		{{0, 1}, {1, 1}, {2, 0}, {2, 1}},
		{{0, 0}, {1, 0}, {1, 1}, {1, 2}}
	},
	{
		{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
		{{0, 2}, {1, 0}, {1, 1}, {1, 2}}
	},
	{
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}}
	},
	{
		{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
		{{0, 1}, {0, 2}, {1, 0}, {1, 1}},
		{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
		{{0, 1}, {0, 2}, {1, 0}, {1, 1}}
	},
	{
		{{0, 0}, {1, 0}, {1, 1}, {2, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
		{{0, 1}, {1, 0}, {1, 1}, {2, 1}},
		{{0, 1}, {1, 0}, {1, 1}, {1, 2}}
	},
	{
		{{0, 1}, {1, 0}, {1, 1}, {2, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
		{{0, 1}, {1, 0}, {1, 1}, {2, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {1, 2}}
	}
};
const int scr[5] = {0, 100, 250, 400, 1000};
inline int mc(char c)
{
	switch (c)
	{
		case 'I': return 0;
		case 'J': return 1;
		case 'L': return 2;
		case 'O': return 3;
		case 'S': return 4;
		case 'T': return 5;
		default: return 6; //case 'Z': return 6;
	}
}
inline int ma(int x) {return x / 90;}
const int W = 30001, H = 120007;
struct Row;
struct Node
{
	Node *u, *d;
	Row* r;
	int c;
	Node(Row* R = NULL, int C = 0): u(NULL), d(NULL), r(R), c(C) {}
} *top[W], *bot[W];
struct Row : public vector<Node*> {
	int h;
	Row *u, *d;
	Row(int H = 0): h(H), u(NULL), d(NULL) {}
	Row* go(int);
} r[H], *null = new Row(-1); //*r[H];
Row* Row::go(int d)
{
	Row* ret = this;
	while (d < 0)
	{
		ret = ret -> d;
		if (ret == NULL) return null;
		//�˴�����һ������null�ڵ㣬���ⷵ��NULL�����δ��� 
		//����null��h������Ϊһ��������Ӱ��𰸵�ֵ����-1 
		//�������ֶδ���ʱ���ɿ��ǲ�ȡ�ô�ʩ 
		d++;
	}
	while (d > 0) {ret = ret -> u; d--;}
	return ret;
}
//Row�����ü̳�ʵ�֣�������ɽ�r.v.push_back()�򻯳�r.push_back()������ԺͿɶ������� 
//�̶���ͷ�������������ָ�룻�����ָ�붼�����õ�ʱ�򣬾�����ѡ�����飬�����ʴ������ 
Row* getPos(int pos, const int (*b)[2])
{
	Row* ret;
	int h = -1;
	for (int i = 0; i < 4; i++)
		if (i == 0 || b[i][0] != b[i-1][0])
		{
			int tc = pos + b[i][0];
			Row* tr = top[tc] -> r -> go(-b[i][1]);
			if (tr -> h > h) {h = tr -> h; ret = tr;}
		}
	return ret -> u;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		//��ʼ�������е�������ʼ�����б�ͷ 
		for (int i = 0; i < H; i++)
		{
			r[i].h = i;
			if (i < H-1) r[i].u = &r[i+1]; 
			if (i > 0) r[i].d = &r[i-1];
			r[i].clear();
		}
		for (int i = 0; i < W; i++) bot[i] = top[i] = new Node(&r[0], i);
		
		int w, n;
		cin >> w >> n;
		int res = 0;
		while (n--)
		{
			//���뷽����������㷽����� 
			char c;
			int pos, a;
			cin >> c >> pos >> a;
			const int (*b)[2] = B[mc(c)][ma(a)];
			Row* cur = getPos(pos, b);
			
			//��������ÿһ���������������������е�vector 
			vector<Row*> ful;
			for (int i = 0; i < 4; i++)
			{
				Row* tr = cur -> go(b[i][1]);
				int tc = pos + b[i][0];
				Node* tmp = new Node(tr, tc);
				tr -> push_back(tmp); top[tc] -> u = tmp; tmp -> d = top[tc]; top[tc] = tmp;
				if (tr -> size() == w) ful.push_back(tr);
			}
			
			//���������У��ڸ��б�ͷ��������У��������е�������ɾ�����еĿ� 
			if (!ful.empty())
			{
				res += scr[ful.size()];
				for (auto cr : ful)
				{
					for (const auto& i : *cr) //����д�����ɵ��Ƕ������ڶ���ĳ����� 
					{
						i -> d -> u = i -> u;
						if (i -> u != NULL) i -> u -> d = i -> d;
						if (top[i->c] == i) top[i->c] = i -> d;
						delete i;
					}
					cr -> d -> u = cr -> u;
					if (cr -> u != NULL) cr -> u -> d = cr -> d;
				}
				/*
				Դ��������һ��С���⣬��ÿ�η��뷽������ȥ�Ĳ�һ�����������ţ� 
				��������Ҫ����ʵ����ȥ�����Ƿ�����������÷֣�������ֻ��һ����ȥ�˼��š�
				��Ȼ���ڲ������ݽ�����û�г��������Ĳ��Ե㡣 
				*/
			}
		}
		
		//����� 
		for (Row* tmp = r[0].u; tmp != NULL; tmp = tmp -> u) tmp -> h = tmp -> d -> h + 1;
		cout << "Case #" << k << ':' << endl << res << endl << top[0] -> r -> h;
		for (int i = 1; i < w; i++) cout << ' ' << top[i] -> r -> h;
		cout << endl;
		
		//�����ڴ� 
		for (int i = 0; i < W; i++)
			for (Node* tmp = bot[i]; tmp != NULL; )
			{
				Node* utmp = tmp -> u;
				delete tmp;
				tmp = utmp;
			}
	}
	
	return 0;
}
//�ο���https://www.cnblogs.com/ichn/p/7615788.html 

