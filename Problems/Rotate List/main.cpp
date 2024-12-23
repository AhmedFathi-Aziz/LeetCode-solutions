class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        ListNode *tail = head;
        int length = 1;
        while (tail->next) {
            length++;
            tail = tail->next;
        }
        
        k %= length;
        if (k == 0)
            return head;
        length -= k;
        ListNode *current = head;
        while (--length)
            current = current->next;
            
        ListNode *output = current->next;
        current->next = nullptr;
        tail->next = head;
        return output;
    }
};
