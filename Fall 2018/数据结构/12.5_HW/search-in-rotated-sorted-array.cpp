//leetcode - search in rotated sorted array
/*
����ͨ�����ֲ����ҵ����ֵ�㣨��Ϊ���ǿ���ͨ������nums[low], nums[mid], nums[high]
����Ĵ�С��ϵ֪�����ֵ�������䣩��Ȼ����nums�ֳɵ��������������ڷֱ���ֲ��Ҽ��� 
*/
class Solution
{
public:
    int search(const vector<int>& nums, int target)
    {
        if (nums.empty()) return -1;
        int mx = getMaximum(nums);
        int r1 = binarySearch(nums, 0, mx, target), r2 = binarySearch(nums, mx+1, nums.size()-1, target);
        return r1 == -1 ? r2 : r1;
    }
private:
    int getMaximum(const vector<int>& nums)
    {
    	//���������ı�ʽ���Ǻܶ�ģ��������ֻͨ��midһ�����Ϣ�ж���һ��Ӧ�������䣬��ôд�����Լ򵥺ܶ� 
    	//Ȼ���˴������õ��������������Ϣ������ֻ��ʹ���������Գ�ª��д���� 
        int Low = 0, High = nums.size()-1, ret;
        if (nums[Low] < nums[High]) return High;
        while (Low + 1 < High) //���Low == High �� Low + 1 == High�ˣ���ʱ�������������ص㣬��ֹͣ�������� 
        {
            int Mid = (Low + High) / 2;
            if (nums[Low] < nums[Mid]) Low = Mid;
            else High = Mid - 1;
        }
        return nums[Low] < nums[High] ? High : Low;
    }
    int binarySearch(const vector<int>& nums, int Low, int High, int target)
    {
    	//�˴�ֻ��ҪMidһ�����Ϣ�����Բ�����������ô�鷳�� 
        while (Low <= High)
        {
            int Mid = (Low + High) / 2;
            if (target == nums[Mid]) return Mid;
            else if (target < nums[Mid]) High = Mid - 1;
            else Low = Mid + 1;
        }
        return -1;
    }
};

