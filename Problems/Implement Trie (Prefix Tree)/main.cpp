class Trie {
private:
    Trie *child[26];
    bool is_leaf = {};
public:
    Trie() {
        memset(child, 0, sizeof(child));
    }
    
    void insert(string word, int index = 0) {
        if (index == (int) word.size()) {
            is_leaf = true;
        } else {
            int current = word[index] - 'a';
            if (!child[current])
                child[current] = new Trie();
            child[current]->insert(word, index + 1);
        }
    }
    
    bool search(string word, int index = 0) {
        if (index == (int) word.size())
            return is_leaf;
        int current = word[index] - 'a';
        if (!child[current])
            return false;
        return child[current]->search(word, index + 1);
    }
    
    bool startsWith(string prefix, int index = 0) {
        if (index == (int) prefix.size())
            return true;
        int current = prefix[index] - 'a';
        if (!child[current])
            return false;
        return child[current]->startsWith(prefix, index + 1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
