class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0;
        int b = 0;
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (ptrA) {
            ++a;
            ptrA = ptrA->next;
        }
        while (ptrB) {
            ++b;
            ptrB = ptrB->next;
        }
        int diff = abs(a - b);
        ptrA = headA;
        ptrB = headB;
        if (b > a)
            swap(ptrA, ptrB);
        while (diff--)
            ptrA = ptrA->next;
        while (ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
};
