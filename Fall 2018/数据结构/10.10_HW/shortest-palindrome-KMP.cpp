//leetcode - shortest palindrome
//KMP(4ms)
//��ΪKMP��Next����ĺ������Next[i]=s[0..i-1]��ǰ׺���ں�׺������ȣ���������
//��s����������Ϊrev(s)����Ȼ���c = s+'#'+rev(s)����ַ�����һ��Next���飨�м��
//�ָ������Ƿ�ֹrev(s)��s����һ���´𰸴��󣩣���ʱNext[len(c)]����ľ���
//s�������ǰ׺���ȣ��Ӷ����Ĵ���rev��ǰ(len(s)-Next[len(c)])���ַ�+s�� 
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s; reverse(rev.begin(), rev.end());
        string c = s + '#' + rev;
        int* Next = new int [c.size()+1];
        GetNext(c, Next);
        return rev.substr(0, s.size() - Next[c.size()]) + s;
    }
private:
    void GetNext(const string& s, int* Next)
    {
        int len = s.size(), i = 0, k = -1;
        Next[0] = -1;
        while (i < len)
        {
            if (k == -1 || s[i] == s[k])
			{
				Next[++i] = ++k;
				if (s[i] == s[k]) Next[i] = Next[k];
			}
            else k = Next[k];
        }
    }
};

