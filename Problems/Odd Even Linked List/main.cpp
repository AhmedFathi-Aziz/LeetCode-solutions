class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next ||
            !head->next->next)
            return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *current = head;
        ListNode *ptr = even;
        int i = 1;
        while (current) {
            if (i > 2) {
                if (i & 1) {
                    odd->next = current;
                    odd = current;
                } else {
                    even->next = current;
                    even = current;
                }
            }
            current = current->next;
            ++i;
        }
        even->next = nullptr;
        odd->next = ptr;
        return head;
    }
};
