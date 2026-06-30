class Solution {
public:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k--)
            curr = curr->next;
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {

            // Find kth node
            ListNode* kth = getKth(groupPrev, k);

            if (!kth)
                break;

            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            // Connect reversed group
            ListNode* temp = groupPrev->next;

            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }
};
