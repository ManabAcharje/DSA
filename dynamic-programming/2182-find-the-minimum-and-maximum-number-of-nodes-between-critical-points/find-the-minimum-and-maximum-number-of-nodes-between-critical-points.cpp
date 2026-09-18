class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if (head == nullptr || 
            head->next == nullptr || 
            head->next->next == nullptr) {
            return {-1, -1};
        }

        ListNode* curr = head->next;
        ListNode* prev = head;
        ListNode* nest = curr->next;

        int first = -1;
        int last = -1;
        int mini = INT_MAX;
        int idx = 1;

        while (nest) {

            if ((curr->val > prev->val && curr->val > nest->val) ||
                (curr->val < prev->val && curr->val < nest->val)) {

                if (first == -1) {
                    first = idx;
                }
                else {
                    mini = min(mini, idx - last);
                }

                last = idx;
            }

            prev = curr;
            curr = nest;
            nest = nest->next;
            idx++;
        }

        if (mini == INT_MAX)
            return {-1, -1};

        return {mini, last - first};
    }
};