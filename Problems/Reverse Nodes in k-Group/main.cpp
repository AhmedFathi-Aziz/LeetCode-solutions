class Solution {
public:
    ListNode *get(ListNode *node, int k) {
        while (node && k) {
            node = node->next;
            k--;
        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode *groupPrev = &dummy;
        while (true) {
            ListNode *kthNode = get(groupPrev, k);
            if (kthNode == nullptr)
                break;
            
            ListNode *current = groupPrev->next;
            ListNode *prev = kthNode->next;
            ListNode *groupNext = kthNode->next;
            while (current != groupNext) {
                ListNode *next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            ListNode *tmp = groupPrev->next;
            groupPrev->next = prev;
            groupPrev = tmp;

        }
        return dummy.next;
    }
};
