class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode *output = &dummy;
        ListNode *node = nullptr;
        while (head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    node = head;
                    head = head->next;
                    delete node;
                }
                node = head;
                head = head->next;
                delete node;
            } else {
                output->next = head;
                output = head;
                head = head->next;
            }
        }
        output->next = nullptr;
        return dummy.next; 
    }
};
