//leetcode - maximal rectangle
//����ջ 
//��ȻҪ��������Ž⣬ÿ��������Ҫ������һ�Σ����Ҫ����ʱ�临�Ӷ�ΪO(n*n)����ô
//ÿ����Ϊ�������½�ʱ�ľֲ����Ž�Ҫ��O(1)ʱ������� 
//����˼��ʲô���Ľ���ܻ��Ǿֲ����Ž⣬��������һ������: �����ǰ����ұߴ���һ�㣬 
//���Ӧ�ĸ߶�ֵ�ȵ�ǰ��ĵͣ���ô��ǰ��ĸ߶�ֵ�Դ�û��Ӱ�죨���ο����������� 
//����ǰ������һ�У���Ҳ����˵���ȿ����ָ��ߵĵ�û�б���ı�Ҫ 
//������һ���ʣ�����ÿһ�У��������һ��ջ������������С��������������ǰ�е� 
//�߶ȴ���ջ����¼�������ĸ߶ȣ�����ջΪ�գ������ջ��ǰ�кţ����򲻶ϳ�ջ������ 
//ÿ�γ�ջ������һ��Ⲣ���´𰸣�ֱ���ٴ����㵱ǰ�и߶ȴ���ջ����¼�������ĸ� 
//�ȣ�Ȼ���ջ��ǰ�кš� 
//����������ʱ��ջ���кŶ�Ӧ�ĸ߶��������к����Ӷ��������ӵģ����Գ�Ϊ����ջ  
class Solution {
public:
    int maximalRectangle(const vector<vector<char>>& matrix)
    {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ones(n+1, vector<int>(m, 0));
        int ret = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
                if (matrix[i-1][j] == '1') ones[i][j] = ones[i-1][j] + 1;
                else ones[i][j] = 0;
            ret = max(ret, maxAreaCurRow(ones[i]));
        }
        return ret;
    }
private:
    int maxAreaCurRow(vector<int>& heights)
    {
        if (heights.empty()) return 0;
        heights.push_back(0); //����������Բ���������ѭ�������Ժ�������ջ��ʣ���Ԫ��  
        stack<int> s;
        int ret = 0;
        for (int i = 0; i < heights.size(); i++)
            if (s.empty() || heights[i] > heights[s.top()]) s.push(i);
            else {
                while (!s.empty() && heights[i] <= heights[s.top()])
                {
                    int tmp = s.top(); s.pop();
                    int w = s.empty() ? i : i-s.top()-1;
                    ret = max(ret, w * heights[tmp]);
                }
                s.push(i);
            }
        return ret;
    }
};
//https://blog.csdn.net/magicbean2/article/details/68486631
//Ŀ��������Ҫ�õ������е���ջ�ģ������Ҳ���д��ֻ����ǰ����˵�������㷨���ѣ�
//ֻ��ֱ���������QAQ 

