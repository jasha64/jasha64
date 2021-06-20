//leetcode - Implement strStr()
//ģ���⣬���ַ������˴�����KR�㷨(AC, 4ms) 
class Solution
{
public:
    int strStr(string t, string p)
    {
        unsigned int ht = 0, hp = 0, d = 1; //text�Ĺ�ϣֵ, pattern�Ĺ�ϣֵ 
        //����pattern�Ĺ�ϣֵ��textǰ׺�Ĺ�ϣֵ
        int lt = t.size(), lp = p.size();
        for (int i = 0; i < lp; i++) hp = (hp << 1) + p[i];
        for (int i = 0; i < lp; i++) ht = (ht << 1) + t[i]; 
        for (int i = 1; i < lp; i++) d <<= 1;
		//����h(x) = x % MOD��Ϊ��ϣ�������Ӷ�������O(1)ʱ��������ƶ�����ʱ��ϣ���������¼���  
        for (int i = 0; i+lp <= lt; i++)
        {
            if (ht == hp && p == t.substr(i, lp)) return i; //�����ϣֵ��ȣ����ж��ַ����Ƿ���� 
            ht = (ht-t[i]*d << 1) + t[i+lp]; //���ƴ���1λ�������ϣֵ 
            //ht = (ht-(t[i] << lp-1) << 1) + t[i+lp] ����д����WA, ��Ϊ��lp-1�������Ϳ��ʱ���Զ���lpȡģ, ��������Ȼ��� 
        }
        return -1;
    }
};

