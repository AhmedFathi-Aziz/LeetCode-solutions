class Trie {
public:
    Trie *child[26];
    bool is_leaf = false;
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
};
bool dfs(string s, int index, Trie *root, Trie *trie, vector<int> &memo) {
    if (index == s.size())
        return true;
    int &ret = memo[index];
    if (~ret)
        return ret;
    for (int i = index; i < s.size(); i++) {
        int current = s[i] - 'a';
        if (!root->child[current])
            return ret = false;
        root = root->child[current];
        if (root->is_leaf && dfs(s, i + 1, trie, trie, memo))
            return ret = true;
    }
    return ret = false;
}
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (string word : wordDict) {
            trie.insert(word);
        }
        vector<int> memo(301, -1);
        return dfs(s, 0, &trie, &trie, memo);
    }
};
