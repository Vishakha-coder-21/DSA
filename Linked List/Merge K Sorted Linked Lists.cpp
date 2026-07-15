class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto x : lists)
            if (x) pq.push(x);

        ListNode dummy, *tail = &dummy;

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            tail = tail->next = t;
            if (t->next) pq.push(t->next);
        }

        return dummy.next;
    }
};
