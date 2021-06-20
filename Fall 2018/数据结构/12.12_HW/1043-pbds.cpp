//10.131.235.233 1043 zoo
//ƽ����(pbds)
#include <iostream>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdlib>
using namespace std;
using namespace __gnu_pbds;

typedef pair<long long, int> pii;
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Tree;
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
		//pbds���ƽ�����ǲ�֧���ظ�Ԫ�صģ�ֻ�ܲ�ȡ���ֶ��ˣ����ִ���ʽ�����Դ���ϴ�������ͬѧ�ڰ��Ͻ��Ĳ������ݣ� 
		while (rr < q[i].r) {rr++; Tree.insert(pii(val[rr], rr));} 
		while (ll < q[i].l) {Tree.erase(pii(val[ll], ll)); ll++;}
		out[q[i].no] = Tree.find_by_order(q[i].k - 1) -> first; //������0��ʼ 
	}
	
	for (int i = 0; i < m; i++) cout << out[i] << endl;
	return 0;
}

