class Stack {
public:
	int length;
	ListNode *head;
	int capacity;
	Stack (int capacity) {
		this->capacity = capacity;
		length = 0;
		head = nullptr;
	}
	~Stack() {
		while (head) {
			ListNode *current = head;
			head = head->next;
			delete current;
		}
	}

	bool isEmpty() {
		if (!head)
			return true;
		return false;
	}
	
	int size() {
		return length;
	}
	
	int top() {
		if (isEmpty())
			return -1;
		return head->data;
	}
	
	void push(int element) {
		if (length == capacity)
			return cout << "Full" << '\n', void();
		++length;
		ListNode *newNode = new ListNode(element);
		if (isEmpty()) {
			head = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
	}
	
	void pop() {
		if (isEmpty()) {
			return cout << "Empty" << '\n', void();
		}
		--length;
		ListNode *current = head;
		head = head->next;
		delete current;
	}
};
