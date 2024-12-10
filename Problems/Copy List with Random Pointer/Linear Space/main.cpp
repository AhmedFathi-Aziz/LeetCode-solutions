class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node *current = head;
        while (current) {
            Node *newNode = new Node(current->val);
            mp[current] = newNode;
            current = current->next;
        }
        current = head;
        while (current) {
            mp[current]->next = mp[current->next];
            mp[current]->random = mp[current->random];
            current = current->next;
        }
        return mp[head];
    }
};
