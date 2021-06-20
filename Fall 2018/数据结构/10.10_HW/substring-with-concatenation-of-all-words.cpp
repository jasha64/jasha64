//leetcode - substring with concatenation of all words
//ģ�� 
class Solution
{
public:
    vector<int> findSubstring(string t, const vector<string>& words)
    {
        if (words.empty()) return vector<int>();
        const int lp = words.front().size(), lt = t.size();
        map<string, int> pc; //words��ÿ�����ʳ����˼��� 
        for (auto s : words)
        {
        	if (s.size() != lp) return vector<int>(); //�������ݲ��Ϸ������ؿռ� 
        	if (pc.find(s) != pc.end()) pc[s]++;
        	else pc[s] = 1;
        }
        vector<int> ret;
        for (int i = 0; i < lp; i++) //�Դ������Ϊi+k*lp��ÿ������������ۣ�iӦ�ô�0��lp-1ѭ������������п������ 
        {
        	map<string, int> cc; //current count
        	int cnt = 0, L = i; //L: ������� 
        	for (int j = L; j+lp <= lt; j += lp)
        	{
        		string c = t.substr(j, lp);
        		if (pc.find(c) != pc.end())
        		{
        			if (cc.find(c) != cc.end()) cc[c]++;
        			else cc[c] = 1;
        			cnt++;
        			while (cc[c] > pc[c]) //words��ĳ�����ʵĳ��ִ������� 
        			{
        				//��һֱ���ƴ�����ˣ�ֱ��������ʵĳ��ִ����ص�������Χ 
        				cc[t.substr(L, lp)]--; cnt--;
        				L += lp;
        			}
        			if (cnt == words.size()) //words�еĵ��ʳ�ȫ�� 
        			{
        				ret.push_back(L); //ͳ�ƴ� 
        				cc[t.substr(L, lp)]--; cnt--;
        				L += lp; //�����������lp������ͳ�� 
        			}
        		}
        		else {
        			//jλ�ó����˲���words�еĵ��� 
        			L = j + lp; //����ֱ�ӰѴ�������ƶ���j+lp�ˣ�������Ȼ������������ 
        			cc.clear(); cnt = 0;
        		}
        	}
        }
        return ret;
    }
};
//�ο�: https://blog.csdn.net/linhuanmars/article/details/20342851
//һ��ʼ������KMPд������������������֮��û�뵽������Ǳ��������ˣ� 

