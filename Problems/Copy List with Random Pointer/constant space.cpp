/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* current = head;
        while (current) {
            Node*next = current->next;
            current->next = new Node(current->val);
            current->next->next = next;
            current = next;
        }
        
        current = head;
        while (current) {
            if (current->random)
                current->next->random = current->random->next;
            current = current->next->next;
        }

        Node* list = new Node(0);
        Node* out = list;
        while (head) {
            list->next = head->next;
            list = list->next;
            head->next = head->next->next;
            head = head->next;
        }
        return out->next;
    }
};