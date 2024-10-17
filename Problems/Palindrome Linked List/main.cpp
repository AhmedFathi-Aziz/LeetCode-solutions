/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (slow) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode *current = head;
        while (prev) {
            if (prev->val != current->val)
                return false;
            prev = prev->next;
            current = current->next;
        }
        return true;
    }
};
