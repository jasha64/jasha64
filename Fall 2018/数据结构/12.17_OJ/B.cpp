#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
struct Line
{
    ll A, B; //�����õ�A��B��˵ĵط�̫���ˣ�Ϊ��̷���������Ҵ���Կռ�Ҫ�󲻸ߣ��ɴ�ֱ��������long long���ˣ����ⷴ��дǿ������ת�� 
    friend bool operator < (const Line& a, const Line& b) {return a.A * b.B < b.A * a.B;}
    friend bool operator == (const Line& a, const Line& b) {return a.A == b.A && a.B == b.B;}
} line[100001];
ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
inline ll C2(ll x) {return x * (x - 1) / 2;}
inline ll dot(Line a, Line b) {return a.A * b.A + a.B * b.B;}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll A0 = 0, B0 = 0; //A��BΪ0��ֱ�߼��� 
    for (int i = 0, disc; i < n; i++)
    {
        ll& A = line[i].A;
        ll& B = line[i].B;
        cin >> A >> B >> disc; //discard C
        if (A == 0) {A0++; i--; n--; continue;}
        else if (B == 0) {B0++; i--; n--; continue;} //�Ȱ�A��BΪ0�ĵ����߳�ȥ���Ӷ��������� 
        int c = gcd(A, B); A /= c; B /= c;
        if (A < 0) {A = -A; B = -B;} //���ܺ���һ�н�������Ϊgcd������-1���Ӷ��ֵ���A��ظ��� 
	}
    
    sort(line, line + n);
    ll Res1 = C2(A0) + C2(B0); //n <= 1e5, res1 ~ n*n, Ҫ��long long 
    for (int i = 0, j; i < n; i += j)
	{
        j = 0;
        while (i + j < n && line[i] == line[i+j]) j++;
        Res1 += C2(j);
    }
	ll Res2 = A0 * B0;
	int bd = lower_bound(line, line + n, (Line){.A = 1, .B = 0}) - line; //�����ṹ���������������������˳��������ֱ�ۡ������״� 
	for (int i = 0, j, k = bd; i < bd && k < n; i += j)
	{
		int cnt = 0;
		j = 0;
        while (i + j < bd && line[i] == line[i+j]) j++; //ͳ�Ƴ���i��ͬ�Ƕȵ�ֱ������ 
        while (k < n && dot(line[i], line[k]) > 0) k++;
        while (k < n && dot(line[i], line[k]) == 0) {k++; cnt++;} //ͳ�Ƴ���k��ͬ�Ƕȵ�ֱ������ 
        Res2 += (long long)j * cnt; //��� 
    }
	
    cout << Res1 << ' ' << Res2 << endl;
    return 0;
}

