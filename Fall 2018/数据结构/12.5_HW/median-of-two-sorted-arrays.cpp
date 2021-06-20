//leetcode - median of two sorted arrays
//���� 
/*
"��λ��"��ͳ��ѧ�ϵĶ����ǣ���λ�����������зֳɳ�����ͬ�����������У�����һ���������е�����ֵ������һ��������ֵ�� 
�м��ڴˣ���m��nΪ����A��B�ĳ��ȣ�����������ҵ�һ��i(0 <= i <= m)��j(0 <= j <= n)
��A���зָ��A1 = A[0...i-1]��A2 = A[i...m-1]����B���зָ��B1 = B[0...j-1]��B2 = B[j...n-1]�� 
��A1��B1����һ��õ�AB1��A2��B2����һ��õ�AB2�����i��jʹ��AB1��AB2������ȡ�AB1����С��AB2�� 
���Ǿ͵õ�����λ��������AB1�е����ֵ��AB2�е���Сֵ������� 
���ﵽ�������������i + j == (m + n + 1) / 2����j = (m+n+1) / 2 - i��ʹ�ó������ 
����Ȼj <= n������Ϊȷ��j >= 0����֪i <= m����Ҫ��m <= n�� 
Ȼ����Ϊ�Ѿ�����A1 < A2��B1 < B2��ֻҪA1 < B2����A2 < B1��������ڶ���������Ҳ���� 
A[i-1] <= B[j] && B[j-1] <= A[i]����i, j == 0, m �� n �ı߽�������У� 
�����͵õ���һ��˳����ⷽ����i = 0 ... m-1�������ж�i�Ͷ�Ӧ��j�ǲ��ǽ⡣ 
��ΪA��B�����ź���ģ�����i����A[i-1]��A[i]���B[j]��B[j-1]��С�������е����Եģ� 
�ɴ˾Ϳ���д�����֣��������۶���ÿ��i, j������������� 
���B[j-1] > A[i]��˵��A[i]̫С������Low = i + 1�� 
���A[i-1] > B[j]��˵��A[i-1]̫������High = i - 1�� 
���������������������֣�������������˵�ĵڶ�������������������˽⡣  
*/
class Solution
{
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (nums1.empty()) return findMedian(nums2);
        if (nums2.empty()) return findMedian(nums1);
        if (n < m) return findMedianSortedArrays(nums2, nums1);
        int Low = 0, High = m, halfLen = (m + n + 1) / 2;
        while (Low <= High)
        {
            int i = (Low + High) / 2, j = halfLen - i;
            if (i < High && nums2[j-1] > nums1[i]) Low = i + 1;
            else if (i > Low && nums1[i-1] > nums2[j]) High = i - 1;
            else {
                int maxLeft = i > 0 ? nums1[i-1] : -0x7fffffff;
                if (j > 0) maxLeft = max(maxLeft, nums2[j-1]); //���AB1�����ֵ 
                if ((m + n) % 2 == 1) return maxLeft;
                int minRight = i < m ? nums1[i] : 0x7fffffff;
                if (j < n) minRight = min(minRight, nums2[j]); //���AB2����Сֵ 
                return (maxLeft + minRight) / 2.0;
            }
        }
    }
private:
    double findMedian(const vector<int>& nums)
    {
        int sz = nums.size();
        if (sz == 1) return nums[0];
        if (sz % 2 == 0) return (nums[sz/2] + nums[sz/2-1]) / 2.0;
        else return nums[sz/2];
    }
};
//�ο����ϣ�leetcode solution 

