//leetcode - Implement strStr()
//ģ���⣬���ַ������˴�����KMP�㷨(AC, 4ms) 
//���ϰ��ṩ��KMPģ�����Ҽ�������ģ����üǵģ��ش���л  
class Solution
{
public:
    int strStr(string t, string p)
    {
        if (p.empty()) return 0;
        int i = 0, j = 0, lt = t.size(), lp = p.size();
        int* Next = new int [t.size()];
        GetNext(p, Next);
        while (i < lt && j < lp)
        {
            if (t[i] == p[j]) {i++; j++;}
            else if (Next[j] != -1) j = Next[j];
            else {i++; j = 0;}
        }
        if (j == lp) return i-lp;
        else return -1;
    }
private:
    void GetNext(const string& p, int* Next)
    {
        int i = 0, lp = p.size(), k = -1;
        Next[0] = -1;
        while (i < lp-1)
        {
            if (k == -1 || p[i] == p[k])
            {
                Next[++i] = ++k;
                if (p[i] == p[k]) Next[i] = Next[k];
            }
            else k = Next[k];
        }
    }
};

