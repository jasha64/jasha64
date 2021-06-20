#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 200007;
int a[N], b[N], l[N], r[N];
inline int Dist(int a, int b) {return abs(a-b);}

int main()
{
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 1 && a[i] == a[i-1]) {n--; i--;} //ȥ��
  }
  for (int i = 1; i <= m; i++) cin >> b[i];

  for (int i = 1, j = 1; i <= m; i++) {
    while (j < n && Dist(b[i], a[j]) > Dist(b[i], a[j+1])) j++;
    int c = Dist(b[i], a[j]);
    if (b[i] < a[j]) l[j] = max(c, l[j]);
    else r[j] = max(c, r[j]);
  }
  //c��ʾb[i]����������ŵľ��� 
  //l[j]��ʾ������j��ߵ������д���������������ĲƱ��ľ�������ֵ 
  //r[j]��ʾ......�ұ�......���ֵ 

  long long Res = 2ll * l[1];
  for (int i = 2; i <= n; i++)
    Res += min(2ll * (r[i-1] + l[i]), (long long)a[i] - a[i-1]);
  Res += 2ll * r[n];
  cout << Res << endl;

  return 0;
}

