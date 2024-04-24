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
        Node* buffer = head;
        Node* randompointer = head;
        map<Node*, Node*> mp;

        while (current) {
            Node* thenode = new Node(current->val);
            mp[current] = thenode;
            current = current->next;
        }
        while (buffer) {
            Node *buf = mp[buffer];
            buffer = buffer->next;
            buf->next = mp[buffer];
            buf->random = mp[randompointer->random];
            randompointer = randompointer->next;
        }
        return mp[head];
    }
};