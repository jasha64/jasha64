//leetcode - remove duplicate letters
//����ջ 
//���ַ����е�ÿ���ַ�s[i]���ԣ�����������б���С���ַ�s[j]��������Ӵ�0~s[j]ȥ���ظ��ַ����õĴ𰸣�
//ѡ��s[j]��ѡ��s[i]���ţ�û��Ҫ����s[i]������s[i]�����һ�γ��֣�
//�������ά��һ��ջ��˳������ַ�������ÿ���ַ���ֻҪջ��Ϊ�ն���ջ��Ԫ�رȵ�ǰ 
//�ַ������ջ��Ԫ�ز������һ�γ��־ͳ�ջ����ɳ�ջ����������ջ 
//����һ��������ʱ��ջ��ѡȡ���ַ����������������ַ����г��ֵ�˳�������ģ������������һ���ַ��� 
//ջ�е�Ԫ�ؼ�Ϊѡ���ڴ��е��ַ������ջ�е�Ԫ�شӵ׵����������Ӽ��ô� 
class Solution
{
public:
    string removeDuplicateLetters(const string& str)
	{
    	int cnt['z' + 1] = {};
    	bool vis['z' + 1];
        fill(vis + 'a', vis + 'z' + 1, 1);
        int len = str.size();
        for (auto c : str) {cnt[c]++; vis[c] = 0;}
        
        stack<char> s;
        for (auto c : str)
        {
        	if (vis[c]) {cnt[c]--; continue;} 
            while (!s.empty() && cnt[s.top()] > 0 && c < s.top()) {vis[s.top()] = 0; s.pop();}
            s.push(c); cnt[c]--; vis[c] = 1;
        }
        
        string ret;
        while (!s.empty()) {ret = s.top() + ret; s.pop();}
        return ret;
    }
};

