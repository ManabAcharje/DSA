class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = nullptr, *r = head;

        // move r n steps ahead
        for (int i = 0; i < n; i++) {
            r = r->next;
        }

        // special case: remove head
        if (r == nullptr) {
            return head->next;
        }

        // move all pointers
        while (r != nullptr) {
            r = r->next;
            p = p->next;
            q = (q == nullptr) ? head : q->next;
        }

        // delete p
        q->next = p->next;

        return head;
    }
};