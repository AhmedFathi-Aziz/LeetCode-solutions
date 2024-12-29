class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *current = head->next;
        ListNode *prev = head;

        while (current) {
            if (current->val >= prev->val) {
                prev = current;
                current = current->next;
                continue;
            }
            ListNode *tmp = dummy;

            while (current->val >= tmp->next->val)
                tmp = tmp->next;

            prev->next = current->next;
            current->next = tmp->next;
            tmp->next = current;
            current = prev->next;
        }
        return dummy->next;
    }
};
