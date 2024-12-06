class WordDictionary {
private:
    WordDictionary *child[26];
    bool is_leaf = {};
public:
    WordDictionary() {
        memset(child, 0, sizeof(child));
    }
    
    void addWord(string word, int index = 0) {
        if (index == (int) word.size()) {
            is_leaf = true;
        } else {
            int current = word[index] - 'a';
            if (!child[current]) {
                child[current] = new WordDictionary();
            }
            child[current]->addWord(word, index + 1);
        }
    }
    
    bool dfs(string word, int index = 0) {
        if (index == (int) word.size()) {
            return is_leaf;
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (child[i] and child[i]->dfs(word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int current = word[index] - 'a';
            if (child[current] and child[current]->dfs(word, index + 1)) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool search(string word) {
        return dfs(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
