/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
    Floyd's Tortoise and Hare
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* t = head;
        ListNode* h = head;
        int len = 0;
        while (h && h->next) {
            t = t->next;
            h = h->next->next;
            if (t == h)
                return true;
        }
        return false;
    }
};
