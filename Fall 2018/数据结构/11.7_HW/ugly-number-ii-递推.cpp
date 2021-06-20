//leetcode - ugly number ii
//���ƽⷨ 
//���Ȳ��ѿ�������ĳ�����һ�������ɽ�С�ĳ�������2, 3, 5�õ� 
//��Ȼ����ͨ���õ�ǰ����������2, 3, 5��˳��õ�����ĳ�����������һ�����ȷ���� 
//����ĳ�������2һ���ȸ�С�ĳ�������2�õ��ĳ������� 
//��������ά������ָ��i2, i3, i5, ����ik�ĺ����ǣ�����k�ܵõ��ȵ�ǰ��������ĳ��� 
//�������� 
//����ÿ��ȡa[i2]*2, a[i3]*3, a[i5]*5�е���С�ߣ�������һ��������ע����Ӧ�ظ�������ָ�� 
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> ugnum(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (ugnum.size() < n)
        {
            int n2 = ugnum[i2] * 2, n3 = ugnum[i3] * 3, n5 = ugnum[i5] * 5;
            int nx = min(min(n2, n3), n5);
            if (nx == n2) i2++;
            if (nx == n3) i3++;
            if (nx == n5) i5++;
            //�˴�����д��if... else if... else... ����Ϊ���ܲ�ֹһ����͵�ǰ�������һ��������� 
            ugnum.push_back(nx);
        }
        return ugnum.back();
    }
};
//�ο�����: https://www.cnblogs.com/grandyang/p/4743837.html 

