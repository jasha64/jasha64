typedef pair<int, int> pii;
class Solution {
public:
    ListNode* mergeKLists(const vector<ListNode*>& v) {
        if (v.empty()) return NULL;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        ListNode* pos[v.size()]; //��һ���ж�Ϊ�� 
        for (int i = 0; i < v.size(); i++) pos[i] = v[i];
        for (int i = 0; i < v.size(); i++)
            if (pos[i]) pq.push(pii(pos[i] -> val, i)); //�ڶ����ж�Ϊ�� 
        if (pq.empty()) return NULL;
        int row = pq.top().second; pq.pop(); //�������ж�Ϊ�� 
        ListNode* ret = pos[row];
        ListNode* end = ret;
        pos[row] = pos[row] -> next;
        if (pos[row] != NULL) pq.push(pii(pos[row] -> val, row));
        while (!pq.empty())
        {
            row = pq.top().second; pq.pop();
            end -> next = pos[row]; end = pos[row];
            pos[row] = pos[row] -> next;
            if (pos[row] != NULL) pq.push(pii(pos[row] -> val, row));
        }
        return ret;
    }
};

