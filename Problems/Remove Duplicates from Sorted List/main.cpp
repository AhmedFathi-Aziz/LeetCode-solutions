class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        while (current) {
            while (current->next && 
                current->next->val == current->val) {
                ListNode *node = current->next;
                current->next = current->next->next;
                delete node;
            }
            current = current->next;
        }
        return head;
    }
};
