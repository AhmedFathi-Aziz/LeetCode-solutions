class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode *current = head;
        ListNode *leftPrev = &dummy;
        for (int i = 1; i < left; i++) {
            leftPrev = leftPrev->next;
            current = current->next;
        }

        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        for (int i = left; i <= right; i++) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        leftPrev->next->next = current;
        leftPrev->next = prev;
        return dummy.next;
    }
};
