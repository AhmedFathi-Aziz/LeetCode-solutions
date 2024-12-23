class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
            return head;
        Node *current = new Node();
        stack<Node*> stack;
        stack.push(head);

        while (!stack.empty()) {
            Node *top = stack.top();
            stack.pop();
            if (top->next)
                stack.push(top->next);
            if (top->child)
                stack.push(top->child);
            current->next = top;
            top->prev = current;
            top->child = nullptr;
            current = top;
        }
        head->prev = nullptr;
        return head;
    }
};
