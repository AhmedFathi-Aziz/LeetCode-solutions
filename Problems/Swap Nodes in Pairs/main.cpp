class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *current = head;
        while (current and current->next) {
            ListNode *next = current->next->next;
            ListNode *node = current->next;

            current->next = next;
            node->next = current;
            prev->next = node;
            
            prev = current;
            current = next;
        }
        return dummy->next;
    }
};
