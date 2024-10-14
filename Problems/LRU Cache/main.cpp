class Node {
public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node (int key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    Node *left;
    Node *right;
    int capacity;
    unordered_map<int, Node*> mp;
public:
    LRUCache(int capacity) {
       this->capacity = capacity;
       left = new Node(0, 0);
       right = new Node(0, 0);

       left->next = right;
       right->prev = left; 
    }  
    
    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node *node) {
        node->next = right;
        node->prev = right->prev;

        right->prev->next = node;
        right->prev = node;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
        }
        mp[key] = new Node(key, value);
        insert(mp[key]);
        if (mp.size() > capacity) {
            Node *lru = left->next;
            mp.erase(lru->key);
            remove(lru);
            delete lru;
        }
    }
    ~LRUCache() {
        Node *current = left;
        while (current != nullptr) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
