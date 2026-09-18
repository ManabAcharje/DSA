class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int n = 0;
        ListNode* temp = head;

        while (temp) {
            n++;
            temp = temp->next;
        }

        k %= n;
        if (k == 0)
            return head;

        ListNode* p = head;
        ListNode* q = head;

        // Move q k steps ahead
        while (k--) {
            q = q->next;
        }

        // Maintain gap of k nodes
        while (q->next) {
            p = p->next;
            q = q->next;
        }

        ListNode* newHead = p->next;

        q->next = head;      // connect tail to head
        p->next = nullptr;   // break at new tail

        return newHead;
    }
};