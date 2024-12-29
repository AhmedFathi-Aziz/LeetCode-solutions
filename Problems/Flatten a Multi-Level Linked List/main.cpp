ListNode *merge(ListNode *list1, ListNode *list2) {
	ListNode dummy(0);
	ListNode *p = &dummy;
	while (list1 && list2) {
		if (list1->data < list2->data) {
			p->down = list1;
			list1 = list1->down;
		} else {
			p->down = list2;
			list2 = list2->down;
		}
		p = p->down;
	}
	if (list1) 
		p->down = list1;
	if (list2) 
		p->down = list2;
	return dummy.down;
}

ListNode* flattenTheLinkedList(ListNode* root) {
	ListNode *prev = root;
	root = root->next;
	while (root) {
		prev = merge(prev, root);
		root = root->next;
	}
	ListNode dummy(0);
	ListNode *p = &dummy;
	while (prev) {
		p->next = prev;
		p = p->next;
		prev = prev->down;
	}
	return dummy.next;
}
