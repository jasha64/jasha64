/*
�����и�����İ취����ʱ�䷴�ݣ������Ͱ�"����"�����"����"��
���ǰ��������ݵ���������ÿ�δӲ����㿪ʼ�����������±�ǣ������ѱ�ǵ㼴ֹͣ��ʱ�临�Ӷ�O(n)�� 
*/
#include <iostream>
using namespace std;

const int N = 100001;
int fa[N], sgn[N], op[N];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int v = 2; v <= n; v++) cin >> fa[v];
    for (int i = 1; i <= n; i++) cin >> op[i];
    for (int i = n; i >= 1; i--)
		for (int v = op[i]; v != 0 && sgn[v] == 0; v = fa[v]) sgn[v] = op[i];
	
    if (n >= 2) cout << sgn[2];
    for (int v = 3; v <= n; v++) cout << ' ' << sgn[v];
    cout << endl;
    return 0;
}

