class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return head;
        Node *current = head;
        while (current) {
            Node *newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = current->next->next;
        }
        current = head;
        while (current) {
            if (current->random)
                current->next->random = current->random->next;
            else
                current->next->random = nullptr;
            current = current->next->next;
        }
        current = head;
        Node *list = head->next;
        Node *output = head->next;
        while (current) {
            current->next = current->next->next;
            if (list->next)
                list->next = list->next->next;
            list = list->next;
            current = current->next;
        }
        return output;
    }
};
