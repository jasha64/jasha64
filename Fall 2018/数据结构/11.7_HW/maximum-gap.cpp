//leetcode - maximum gap
//�������� 
//�������������Ը��Ӷ������ַ�������O(n)�������ò���Ҫ�����O(n)�㷨�������Ѿ������� 
//���Ե����������֣��������򡢼������򣬺��߿ռ临�Ӷ�O(max{nums})��ֻ���������ݷ�Χ���޵���� 
//����������ʱ�临�Ӷ�O(d(n+radix))���ռ�O(n+radix)��ֻҪradix��d��̫�󶼿���ʹ�� 
class Solution
{
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.empty()) return 0; //ע���п� 
        RadixSort(nums);
        int ret = 0;
        for (int i = 1; i < nums.size(); i++) ret = max(ret, nums[i] - nums[i-1]);
        return ret;
    }
private:
    static const int M = 8, R = 256, B = 4; //lim for insertion sort; radix; bytes
    void RadixSort(vector<int>& nums)
    {
        const int n = nums.size();
        if (n <= M) {InsertionSort(nums); return;}
		//��������㹻С��ʹ�ò������򣨵��Ǹо�LSD���������õݹ飬������һ�Ż���Ч�����ޣ� 
        vector<int> aux(n);
        //������һ��������һ��ʼд��static vector<int> aux(n);��RE
		//��FAQ��֪�������վ��һ��������в�������һ�������в���ģ�����static��һ��������ж�����������RE
		//���Ծ�����Ҫ�ã�������д��static vector<int> aux; aux.resize(n);��ÿ�������ڵ���ʱ����resizeһ�� 
		//���⣬��Ϊ�������û�еݹ飬�����������Ĵ�СҲ���ڰ�ȫ��Χ�ڣ����ǾͲ���ð���հ�����Ϊstatic�� 
		//�ߴ�ү��static���Ը���Ա�����õ���ñ���ֲ������ã����������������ͱ�����ը�� 
        int cnt[R+1];
        for (int d = 0; d < B; d++)
        {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; i++) cnt[GetDigit(nums[i], d) + 1]++;
            for (int j = 1; j < R; j++) cnt[j] += cnt[j-1];
            for (int i = 0; i < n; i++) aux[cnt[GetDigit(nums[i], d)]++] = nums[i];
            copy(aux.begin(), aux.end(), nums.begin());
        }
    }
    void InsertionSort(vector<int>& nums)
    {
        const int n = nums.size();
        for (int i = 1; i < n; i++) //����ΧΪ[0, i)���ֽ�nums[i]���뵽��Ӧ�ô��ڵ�λ�� 
        {
            int j = i, c = nums[i];
            while (j > 0 && c < nums[j-1]) {nums[j] = nums[j-1]; j--;} //��[0, i)���д���nums[i]��Ԫ������һ�� 
            nums[j] = c;
        }
    }
    int GetDigit(int a, int b) //���a�ڻ���R�µĵ�b+1λ 
    {
        while (b--) a /= R;
        return a % R;
    }
};

