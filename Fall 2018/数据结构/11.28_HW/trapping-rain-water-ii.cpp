//leetcode - trapping rain water ii
//���� 
/*
���"װˮ����"���ǲ���"ģ�⺣ƽ������"�ķ����������ģ��"��ƽ��"����ʱ�����ϸߵ� 
���ӻ���ϵ͵ĸ��ӵĹ��� 
���ȣ��׼��߽��ϵĵ��޷�װˮ����ƽ��ֻҪ������һ���߽���ӵĸ߶Ⱦ�һ���������� 
��Ϊֻ�к�ƽ��ĸ߶ȵ�����Ӹ߶�ʱװˮ��������ܷ����仯������ֻ��Ҫ�ӵ͵������� 
���ʱ߽������еĸ��� 
���ԣ����ǰ�����λ�ڱ߽�ĵ���ΪBFS�������㣬BFSʱÿ��ȡ�������и߶���͵ĵ㣨�� 
Ҫʹ�����ȶ��У�����ά����ƽ��߶�mxΪĿǰ���ѹ��ĵ��е���߸߶� 
��Ϊ��װˮ�ķ�����Χ���ĸ����񶼱��Լ��ߣ�����װˮ�߶�ȡ������Χ�ĸ�������͵�һ 
����ľͰԭ��������ÿ��ȡ�����ȶ��ж��˵ĵ㣬����Χ�ĸ�����δ���ʹ��ļ������ 
���༴ģ�⺣ˮ�������ӵĹ��̣�����������ĸ������бȵ�ǰ��͵ģ��ͰѺͺ�ƽ��߶� 
�Ĳ����𰸣��༴ģ�⺣ˮ�������Ĺ��̣� 
��Ϊ���ȶ��е��趨���ϵ͵ĸ���һ���Ƚϸߵĸ����ȷ��ʣ�������ȷ����������˵ľͰԭ 
��ĳ��� 
*/
class Solution
{
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        if (heightMap.empty() || heightMap[0].empty()) return 0; //�пգ��������heightMap[0]������ 
        priority_queue<Square> pq;
        bool vis[111][111] = {};
        //BFS��ʼ���ǵ�ͼ�߽��ϵĵ� 
        int r = heightMap.size(), c = heightMap[0].size();
        for (int i = 0; i < c; i++)
        {
            pq.push(Square(0, i, heightMap[0][i])); vis[0][i] = 1;
            pq.push(Square(r-1, i, heightMap[r-1][i])); vis[r-1][i] = 1;
        }
        for (int i = 0; i < r; i++)
        {
            pq.push(Square(i, 0, heightMap[i][0])); vis[i][0] = 1;
            pq.push(Square(i, c-1, heightMap[i][c-1])); vis[i][c-1] = 1;
        }
        //������ά��"��ƽ��"�߶� 
        int res = 0, mx = 0;
        while (!pq.empty())
        {
            int curx = pq.top().x, cury = pq.top().y; pq.pop();
            mx = max(mx, heightMap[curx][cury]);
            for (int i = 0; i < 4; i++)
            {
                int nx = curx + dx[i], ny = cury + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                if (heightMap[nx][ny] < mx) res += mx - heightMap[nx][ny];
                pq.push(Square(nx, ny, heightMap[nx][ny]));
            }
        }
        return res;
    }
private:
	static const int dx[4], dy[4];
    struct Square
    {
        int x, y, h;
        Square(int x = 0, int y = 0, int h = 0): x(x), y(y), h(h) {}
        friend bool operator < (const Square& a, const Square& b) {return a.h > b.h;}
    };
};
const int Solution::dx[4] = {-1, 0, 0, 1}, Solution::dy[4] = {0, -1, 1, 0}; //��ĳ�����ԱӦ������˵�������ⶨ�� 
//�ο�����: https://www.cnblogs.com/grandyang/p/5928987.html 

