class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next)
            return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *prev = nullptr;
        while (slow) {
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        slow = head;
        while (prev) {
            ListNode *next = prev;
            prev = prev->next;
            next->next = slow->next;
            slow->next = next;
            slow = slow->next->next;
        }
        slow->next = nullptr;
    }
};
