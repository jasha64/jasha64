#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
using std::domain_error;
using std::max;

void Read(vector<string>& v, string::size_type& maxl)
{
	string s;
	while (cin >> s) {v.push_back(s); maxl = max(maxl, s.size());}
}

int main()
{
	cout << "����������Ӣ�ĵ��ʣ�" << endl;
	string::size_type maxl = 0;
	vector<string> v;
	
	try {
		//���뵥�ʣ��������ĵ��ʣ�ͬʱͳ������ʵĳ����Ա�������
		Read(v, maxl);
		//����Ƿ�õ�����Ч�����룬�����׳��쳣
		if (v.empty()) throw domain_error("no valid input");
	}
	catch (domain_error)
	{
		//û�����뵥�ʲ��׳��쳣ʱ�������쳣�������ʾ��Ϣ�����ط�����ֵ��������
		cout << "δ�����κε��ʣ������ԣ�" << endl;
		return 1;
	}

	//���������������������ʲ����ÿ�����ʳ��ֵĴ���
	cout << "����������" << v.size() << endl;
	sort(v.begin(), v.end());
	cout << "ÿ�����ʳ��ֵĴ�����" << endl;
	int cnt = 0;
	for (vector<string>::size_type i = 0; i < v.size(); i++)
	{
		++cnt;
		if (i == v.size()-1 || v[i] != v[i+1])
		{
			cout << v[i] << string(maxl+1-v[i].size(), ' ') << cnt << endl;
			cnt = 0;
		}
	}

	return 0;
}
