//leetcode - shortest palindrome
//��ϣ����(56ms) �������ܴ󣬽���ʹ�ù�ϣ�㷨�� 
//��Ϊ�����Ч����ӵ�0���ַ���ʼ������Ĵ������Կ��Բ�ȡ��"������Ӵ�"�������ƵĹ�ϣ�㷨
//���赱ǰ�жϵ����Ҷ�Ϊi(ż��)���Ĵ�����ôs[1...i/2]��s[i...i/2+1]�Ĺ�ϣֵ�ض���ͬ 
//���赱ǰ�жϵ����Ҷ�Ϊi(����)���Ĵ�����ôs[1...i/2]��s[i...i/2+2]�Ĺ�ϣֵ�ض���ͬ 
//�Ӵ���Сö��i���ý� 
const int MOD[2] = {19260817, 19660813}, L = 100001, B = 27;
class Solution {
public:
    string shortestPalindrome(string s) {
        s = ' ' + s;
        Init(s);
        int i;
        for (i = s.size()-1; i > 1; i--)
            if (i % 2 == 0 && LHash1(1, i/2) == RHash1(i, i/2+1) && LHash2(1, i/2) == RHash2(i, i/2+1)) break;
            else if (i % 2 != 0 && LHash1(1, i/2) == RHash1(i, i/2+2) && LHash2(1, i/2) == RHash2(i, i/2+2)) break;
        s = s.substr(1);
        for (int j = i; j < s.size(); j++) s = s[j++] + s;
        return s;
    }
private:
    int p[2][L], rh[2][L], lh[2][L]; //hash from right/left
    void Init(const string& s)
    {
        for (int k = 0; k < 2; k++)
        {
            int len = s.size();
            p[k][0] = 1;
            for (int i = 1; i < len; i++) p[k][i] = p[k][i-1] * B % MOD[k];
            lh[k][0] = 0;
            for (int i = 1; i < len; i++) lh[k][i] = (lh[k][i-1] * B + s[i]) % MOD[k];
            rh[k][len] = 0;
            for (int i = len-1; i > 0; i--) rh[k][i] = (rh[k][i+1] * B + s[i]) % MOD[k];
        }
    }
    int LHash1(int b, int e) {return (lh[0][e] - (long long)lh[0][b-1] * p[0][e-b+1] % MOD[0] + MOD[0]) % MOD[0];}
    int LHash2(int b, int e) {return (lh[1][e] - (long long)lh[1][b-1] * p[1][e-b+1] % MOD[1] + MOD[1]) % MOD[1];}
    int RHash1(int b, int e) {return (rh[0][e] - (long long)rh[0][b+1] * p[0][b+1-e] % MOD[0] + MOD[0]) % MOD[0];}
    int RHash2(int b, int e) {return (rh[1][e] - (long long)rh[1][b+1] * p[1][b+1-e] % MOD[1] + MOD[1]) % MOD[1];}
};
//�ο����ϣ�������Ӵ���hash�ⷨ https://blog.csdn.net/yhyyxt/article/details/50538637 

