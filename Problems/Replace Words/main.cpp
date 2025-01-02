class Trie {
private:
    Trie *child[26];
    bool is_leaf = {};
public:
    Trie() {
        memset(child, 0, sizeof(child));
    }

    void insert(const string &word) {
        Trie *current = this;
        for (int i = 0; i < (int) word.size(); i++) {
            int ch = word[i] - 'a';
            if (!current->child[ch])
                current->child[ch] = new Trie();
            current = current->child[ch];
        }
        current->is_leaf = true;
    }

    string root(const string &word) {
        Trie *current = this;
        for (int i = 0; i < (int) word.size(); i++) {
            int ch = word[i] - 'a';
            if (!current->child[ch])
                break;
            if (current->child[ch]->is_leaf)
                return word.substr(0, i + 1);
            current = current->child[ch];
        }
        return word;
    }
   
};

class Solution {
public:
    vector<string> split(const string &sentence) {
        vector<string> ret;
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            ret.push_back(word);
        }
        return ret;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie tree;
        for (string word : dictionary) {
            tree.insert(word);
        }
        vector<string> words = split(sentence);
        string output;
        for (int i = 0; i < words.size(); i++) {
            if (i)
                output += ' ';
            output += tree.root(words[i]);
        }
        return output;
    }
};
