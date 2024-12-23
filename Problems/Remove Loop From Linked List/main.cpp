void removeLoop(ListNode* list) {
	if (!list)
		return;
	ListNode *slow = list;
	ListNode *fast = list;
	ListNode *prev = list;
	while (fast && fast->next) {
		prev = fast->next;
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			fast = list;
			break;
		}
	}
	if (!fast || !fast->next)
		return;
	while (fast != slow) {
		prev = slow;
		slow = slow->next;
		fast = fast->next;
	}
	prev->next = NULL;
}
