class Solution {
public:
    using ll = long long;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *output = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int num = 0;
            if (l1)
                num = l1->val;
            if (l2)
                num += l2->val;

            num += carry;
            carry = num / 10;
            num %= 10;
            dummy->next = new ListNode(num);
            dummy = dummy->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return output->next;
    }
};
