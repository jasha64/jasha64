//leetcode - implement queue using stacks
//������ջʵ�ֶ��еķ����ǣ�һ��ջר�ų��ӣ�һ��ջר����ӣ�һ������Ҫ����ʱ����
//����ջΪ�գ�������ջ�е�ǰ���е�Ԫ�ص����������ջ���ɡ� 
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {b.push(x);}
    
    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (a.empty())
            while (!b.empty()) {a.push(b.top()); b.pop();}
        int ret = a.top(); a.pop(); return ret;
    }
    
    /** Get the front element. */
    int peek()
    {
        if (a.empty())
            while (!b.empty()) {a.push(b.top()); b.pop();}
        return a.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {return a.empty() && b.empty();}
private:
    stack<int> a, b;
};

