class Solution {
public:
    Node *doWork(Node *head) {
        Node *current = head;
        Node *tail = head;
        while (current) {
            Node *next = current->next;
            if (current->child) {
                Node *child = current->child;
                Node *otherTail = doWork(child);

                current->next = child;
                child->prev = current;
                current->child = nullptr;

                otherTail->next = next;
                if (next) next->prev = otherTail;
                if (next) current = next;
            } else {
                current = next;
            }
            if (current)
                tail = current;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if (head)
            doWork(head);
        return head;
    }
};
