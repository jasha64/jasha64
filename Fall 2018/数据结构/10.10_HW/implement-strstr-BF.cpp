//leetcode - Implement strStr()
//ģ���⣬���ַ������˴�����BF�㷨(AC, 8ms) 
class Solution
{
public:
    int strStr(string t, string p) //text, pattern
    {
        int i = 0, j = 0, lt = t.size(), lp = p.size();
        while (i < lt && j < lp)
        {
            if (t[i] == p[j]) {i++; j++;}
            else {i = i-j+1; j = 0;} //ʧ��ʱ���� 
        }
        if (j == lp) return i-lp;
        else return -1;
    }
};

