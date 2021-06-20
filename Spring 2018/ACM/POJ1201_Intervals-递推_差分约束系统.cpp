//��f[N]��ʾ[0, N]������ȡ�˶��ٸ������𰸵���f[N]-f[-1]����Сֵ 
//����������d[N]��ʾ[0, N]����������Ҫȡ���ٸ���������d[-1] = 0����ô�𰸾���d[N] 
//��ϵʽ��d[a-1] + c <= d[b]����������d[i] + 0 <= d[i+1]��d[i+1] - 1 <= d[i]
//���ϲ��Լ��ϵͳ�е��·ģ�ͣ���ͼ���·���� 
#include <iostream>
#include <queue>
using namespace std;

const int N = 50002;
int Head[N];
struct Edge {int w, t, Next;} e[N*3];
int Top = 2;
inline void AddEdge(int S, int T, int W)
{
	e[Top].t = T; e[Top].w = W;
	e[Top].Next = Head[S]; Head[S] = Top++;
}

int d[N];
bool inq[N];
void SPFA()
{
	queue<int> q;
	for (int i = 0; i < N; i++) {q.push(i); inq[i] = 1;}
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = Head[v]; i; i = e[i].Next)
		{
			int u = e[i].t;
			if (d[u] < d[v] + e[i].w)
			{
				d[u] = d[v] + e[i].w;
				if (!inq[u]) {q.push(u); inq[u] = 1;}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0, a, b, c; i < n; i++)
	{
		cin >> a >> b >> c;
		AddEdge(a, b+1, c);
	}
	for (int i = 0; i < N-1; i++) {AddEdge(i, i+1, 0); AddEdge(i+1, i, -1);}
	//��Ϊ��ͼʱ�漰��d[-1]�����ñ�ʾ��������ǰ�����������������ƽ��һ�� 
	
	SPFA();
	
	cout << d[N-1] << endl;
	
	return 0;
}

