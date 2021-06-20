//leetcode - minimum number of refueling stops
//̰�� 
//����Ҫ��������һ�����ۣ�ֻҪһ������վ�ǿɵִ�ģ���ô����λ�ò�Ӱ�����Դ𰸵Ĺ��� 
//�������Ϳ�������㷨��ά����ǰ����tank��ÿ����ǰ��һ������վ�ľ��룬 
//�������ĳ������վ��ʱ��tank<0�ˣ�������ѡ���֮ǰ������Ҳ����������������� 
//�����м���վ�У�ѡ���������ģ���������� 
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        int tank = startFuel;
        priority_queue<int> pq; //priority_queueĬ���Ǵ���ѣ�ԽС���������ȼ�Խ�� 
        int cnt = 0, prev = 0; //��prev�������ɱ������"��ǰ��վ�Ƿ��ǵ�0��"�����ۣ���������� 
        for (auto station : stations)
        {
            int dis = station[0] - prev;
            tank -= dis;
            while (tank < 0) //��Ϊ���ܲ�ֹ����һ�Σ�����Ҫ��while������if 
            {
                if (pq.empty()) return -1;
                tank += pq.top(); pq.pop();
                cnt++;
            }
            pq.push(station[1]); prev = station[0];
        }
        int dis = target - prev;
        tank -= dis;
        while (tank < 0)
        {
            if (pq.empty()) return -1;
            tank += pq.top(); pq.pop();
            cnt++;
        }
        return cnt;
    }
};
//�ο����ϣ�leetcode��solution 

