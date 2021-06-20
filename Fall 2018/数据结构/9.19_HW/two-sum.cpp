class Solution
{
public:
	vector<int> twoSum(vector<int>& v, int t)
	{
		vector<int> ord;
		for (int i = 0; i < v.size(); i++) ord.push_back(i);
		sort(ord.begin(), ord.end(), [&](int a, int b){return v[a] < v[b];});
		//��������
		//[&]��ʾ�õ����ⲿ�����������ô��� 
		//�����������: [&](int a, int b) -> bool {return v[a] < v[b];}, ���ں�����ֻ��һ��return���, ��˿���ʡ�Է���ֵ���� 
		
		//���õ����ԣ���һ��ʱ�临�Ӷ�O(n) 
		for (int i = 0, j = v.size() - 1; i < j; i++)
		{
			while (i < j && v[ord[i]] + v[ord[j]] > t) j--;
			if (i < j && v[ord[i]] + v[ord[j]] == t) return (vector<int>){ord[i], ord[j]};
		}
	}
};

