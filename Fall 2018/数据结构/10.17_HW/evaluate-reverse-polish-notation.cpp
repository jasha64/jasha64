//leetcode - evaluate reverse polish notation
//������ĺ�׺���ʽ��ֵ��ֻ����һ��ջ��������������ջ������������ȡ��ջ�������������������ջ���� 
class Solution {
public:
    int evalRPN(const vector<string>& tokens)
	{
        stack<int> s;
        istringstream is;
        for (auto str : tokens)
        {
            if (str.size() == 1 && !isdigit(str[0]))
            {
                char op = str[0];
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                int c;
                switch (op)
                {
                    case '+': c = a+b; break;
                    case '-': c = b-a; break; //��(��)��ע�ⱻ��(��)���Ǻ��ջ���Ǹ�����ע������˳�� 
                    case '*': c = a*b; break;
                    default: c = b/a; break; //case '/'
                }
                s.push(c);
            }
            else {
                is.str(str);
                int c; is >> c; s.push(c);
                is.clear();
            }
        }
        return s.top();
    }
};

