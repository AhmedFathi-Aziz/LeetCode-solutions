class Trie {
private:
    static const int max_characters = 26;
    Trie* child[max_characters];
    bool is_leaf {};

public:
    Trie() {
        memset(child, 0, sizeof(child));
    }
    
    void insert(string word) {
        Trie* root = this;
        for (int i = 0; i < word.size(); i++) {
            int current = word[i] - 'a';
            if (root->child[current] == 0)
                root->child[current] = new Trie();
            root = root->child[current];
        }
        root->is_leaf = true;
    }
    
    bool search(string word) {
        Trie* root = this;
        for (int i = 0; i < word.size(); i++) {
            int current = word[i] - 'a';
            if (root->child[current] == 0)
                return false;
            root = root->child[current];
        }
        return root->is_leaf;
    }
    
    bool startsWith(string prefix) {
        Trie* root = this;
        for (int i = 0; i < prefix.size(); i++) {
            int current = prefix[i] - 'a';
            if (root->child[current] == 0)
                return false;
            root = root->child[current];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
