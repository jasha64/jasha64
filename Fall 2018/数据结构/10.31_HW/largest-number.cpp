//leetcode - largest number
//��ȻӦ�ð����ֶ�Ӧ���ַ�������ĳ���ֵ����������У�Ȼ�����������������õ��Ĵ����� 
//�����ֵ���Ĺ��򣺣�������|a| < |b|�� 
//����ַ���a�����ַ���b��ǰ׺�����ͨ�����ֵ�����ͬ 
//����ǣ����Բ�ȡһ��͵���İ취��ֱ�ӱȽ�a+b��b+a����a+b < b+a����a < b 
class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), comp);
        string ret, cur;
        for (auto c : nums)
        {
            cur.clear();
            do {
                cur += c % 10 + '0';
                c /= 10;
            } while (c > 0);
            reverse(cur.begin(), cur.end());
            ret += cur;
        }
        int i = 0;
        while (i < ret.size()-1 && ret[i] == '0') i++;
        return ret.substr(i); //ȥ��ǰ��0 
    }
private:
    static bool comp(const int a, const int b)
    {
        char sa[11], sb[11];
        int len1 = sprintf(sa, "%d", a);
        int len2 = sprintf(sb, "%d", b);
        for (int i = 0; i < len1 && i < len2; i++)
            if (sa[i] != sb[i]) return sa[i] > sb[i];
        char sab[21], sba[21];
        strcpy(sab, sa); strcpy(sba, sb);
        strcat(sab, sb); strcat(sba, sa);
        return strcmp(sab, sba) > 0;
    }
};
//���ǿ�������˵������������Բ�����ȷ�������ϵ�� 
//�������a+b < b+a, b+c < c+b, ��֤a+c < c+a. ������ļӺ����ַ�������������� 
//��x = |a|, y = |b|, z = |c|, ��֪����Ϊa*10^y+b < b*10^x+a, b*10^z+c < c*10^y+b, 
//Ҫ֤a*10^z+c < c*10^x+a. ������ļӺ���ͨ���ļӺţ� 
//����֪�����е�����ʽ�ӱ��μ���: a / (10^x-1) < b / (10^y-1) < c / (10^z-1), ����֤ 
//��ͨ�����²���˵���㷨�����������Ž⣺ 
//�������沽�����򣬼��粻��������������򣨼����б��������Ӵ���λ�÷����˽����� 
//��ô��Ȼ����һ�����ڵ�����ԣ������ǽ���һ�¿��Եõ����ŵĽ� 

