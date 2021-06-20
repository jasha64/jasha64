//leetcode - maximum gap
//Ͱ����˼�� 
//������"��"һ�ʴ�ָ�������������Ԫ��֮������ֵ�����������ֵ 
//����Ҫ�����������ҽ������е�Ԫ�ؾ��ȷֲ���ʱ�򣬴�ȡ����Сֵ(mx - mn) / (n-1) 
//����������ֵΪlen�����ǿ��԰�Ԫ�ذ���ֵ���䵽��С��Ϊlen��Ͱ� 
//��Ϊͬһ��Ͱ���Ԫ�������Ĳ�ֵ���ᳬ��len������ͳ�ƴ𰸵�ʱ��ֻ��Ҫͳ�ƺ�һ��Ͱ����Сֵ��ǰһ���ǿ�Ͱ�����ֵ�Ĳ�� 
//ʱ�临�Ӷ�O(n) 
class Solution
{
public:
    int maximumGap(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2) return 0;
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        double len = (double)(mx - mn) / (n - 1); //������int������mx - mn < n-1ʱ����len == 0, ���´𰸴��� 
        if (len < 1e-6) return 0;
        int nb = (mx - mn) / len + 1; //num of blocks
        vector<int> mx_block(nb, INT_MIN), mn_block(nb, INT_MAX);
        for (auto c : nums)
        {
            int b = (c - mn) / len; //������Ԫ��Ӧ�÷ֵ�����Ͱ 
            Tension(mx_block[b], c); Relax(mn_block[b], c);
        }
        int res = 0;
        for (int i = 1, prev_mx = mx_block[0]; i < nb; i++)
        {
            if (mn_block[i] != INT_MAX) Tension(res, mn_block[i] - prev_mx);
            if (mx_block[i] != INT_MIN) prev_mx = mx_block[i];
        }
        return res;
    }
private:
    void Tension(int& a, int b) {if (a < b) a = b;}
    void Relax(int& a, int b) {if (a > b) a = b;}
};
//�ο����ϣ�https://blog.csdn.net/accepthjp/article/details/54098370 

