struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int key, int value) : key(key), 
    value(value), next(nullptr), prev(nullptr) {}
};
class LRUCache {
    int capacity;
    Node *left;
    Node *right;
    unordered_map<int, Node*> mp;

    void pop(Node *node, bool flag = true) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if (flag)
            delete node;
    }
    void push(Node *node) {
        node->next = right;
        node->prev = right->prev;

        right->prev->next = node;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            Node *node = it->second;
            pop(node, false);
            push(node);
            return node->value;
        }
        return -1;
    }
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            pop(it->second);
            mp.erase(it);
        }
        mp[key] = new Node(key, value);
        push(mp[key]);
        if (mp.size() > capacity) {
            Node *lru = left->next;
            mp.erase(lru->key);
            pop(lru);
        }
    }
    ~LRUCache() {
        Node *current = left;
        while (current) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};
