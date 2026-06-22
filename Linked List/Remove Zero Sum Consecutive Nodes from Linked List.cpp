class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> last;
        last.reserve(2048);
        last.max_load_factor(0.7f);

        int sum = 0;
        for (ListNode* cur = &dummy; cur; cur = cur->next) {
            sum += cur->val;
            last[sum] = cur;
        }

        sum = 0;
        for (ListNode* cur = &dummy; cur; cur = cur->next) {
            sum += cur->val;
            cur->next = last[sum]->next;
        }

        return dummy.next;
    }
};
