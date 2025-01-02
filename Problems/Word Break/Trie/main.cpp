struct Node {
    unordered_map<int, Node*> child;
    bool is_leaf = false;
};

class Trie {
private:
    Node *root;
public:
    
    Trie() : root(new Node()) {}
    ~Trie() {
        delete root;
    }

    void insert(const string &word) {
        auto current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->child.find(index) == current->child.end())
                current->child[index] = new Node();
            current = current->child[index];
        }
        current->is_leaf = true;
    }
    
    bool doWork(int index, const string &word, vector<int> &memo) {
        if (index == word.size())
            return true;
        int &ret = memo[index];
        if (!ret)
            return ret;
        auto current = root;
        for (int i = index; i < (int) word.size(); i++) {
            int ch = word[i] - 'a';
            if (current->child.find(ch) == current->child.end())
                break;
            current = current->child[ch];
            if (current->is_leaf) {
                if (doWork(i + 1, word, memo))
                    return ret = true;
            }
        }
        return ret = false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie tree;
        for (string word : wordDict) {
            tree.insert(word);
        }
        vector<int> memo(301, -1);
        return tree.doWork(0, s, memo);
    }
};
