class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0, nullptr);
        ListNode *l = left;
        ListNode *h = right;
        while (head) {
            if (head->val < x) {
                left->next = head;
                left = head;
            } else {
                right->next = head;
                right = head;
            }
            head = head->next;
        }
        right->next = nullptr;
        left->next = h->next;
        head = l->next;
        delete l;
        delete h;
        return head;
    }
};
