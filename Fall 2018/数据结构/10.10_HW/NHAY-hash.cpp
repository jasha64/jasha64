//SPOJ - a needle in the haystack
//��ϣ��������һ��ϵͳ��ѧϰ��ϣ��(0.11s)
#include <cstdio>
#include <cstring>
using namespace std;

const int B = 27, MOD1 = 19260817, MOD2 = 19660813; //base, ˫ģ�� 
const int L = 1000001;
inline int idx(char c) {return c - 'a' + 1;}
int p1[L], p2[L]; //power
struct Str
{
	int h1[L], h2[L], len; //hash value
	char s[L];
	void Init()
	{
		len = strlen(s);
		h1[0] = h2[0] = 0;
		for (int i = 0; i < len; i++)
		{
			h1[i+1] = (h1[i] * B + idx(s[i])) % MOD1; //�������ұ���������ʾ����ֹԽ�� 
			h2[i+1] = (h2[i] * B + idx(s[i])) % MOD2;
		}
	}
	int Hash1(int b, int e) {return (h1[e+1] - (long long)h1[b] * p1[e+1-b] % MOD1 + MOD1) % MOD1;}
	int Hash2(int b, int e) {return (h2[e+1] - (long long)h2[b] * p2[e+1-b] % MOD2 + MOD2) % MOD2;}
	bool Check(int h1, int h2, int b, int e) {return Hash1(b, e) == h1 && Hash2(b, e) == h2;}
} t; //text
char p[L];

int main()
{
	//init hash powers
	p1[0] = p2[0] = 1;
	for (int i = 1; i < L; i++) {p1[i] = p1[i-1] * B % MOD1; p2[i] = p2[i-1] * B % MOD2;}
	
	int len, hp1, hp2; //hash 1,2 of pattern
	bool First = 1;
	while (scanf("%d", &len) == 1)
	{
		if (!First) printf("\n");
		else First = 0;
		
		scanf("%s", p);
		hp1 = hp2 = 0;
		for (int i = 0; i < len; i++) {hp1 = (hp1 * B + idx(p[i])) % MOD1; hp2 = (hp2 * B + idx(p[i])) % MOD2;}
		
		scanf("%s", t.s); t.Init();
		for (int i = 0; i + len <= t.len; i++)
			if (t.Check(hp1, hp2, i, i+len-1)) printf("%d\n", i);
		//ȡģǰ�Ĺ�ϣֵ��������ϣ��ȡģ�����ĸ��ʺ�С����������ֻҪ��ϣֵ������ǾͿ�����Ϊ�ַ�������� 
		//�ɴ���ȥ�˹�ϣֵ���ʱ��O(n)�Ƚϣ�ʹ�������㷨�ĸ��ӶȽ�Ϊ���� 
	}
	
	return 0;
}
//�ο����ϣ������ͬѧ�ṩ�ı��; ��ϣ�㷨����https://www.cnblogs.com/Slager-Z/p/7807011.html
//���ƻ������ܺ���ģ�������ӣ����ұ�������ַ���Ӧ���ֵ����ֵ 
//��Ҫ���κ��ַ���Ӧ��0������ᵼ������"ab" == "b"���������⣨�������a->0�Ļ�����һ��ذ�a-z��Ӧ��1-26�ȽϺ��� 
//��Ȼ���ȡģ��ѡ��һ��1e9��ģ�������ױ���������ѡ����1e9�������ڿ������ҳ�һ��1e18�����Ҿ���ѡ������ 

