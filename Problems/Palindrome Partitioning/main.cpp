class Solution {
    vector<vector<string>> output;
    vector<string> sofar;

    bool isPalindrome(string &word) {
        int i = 0,
        j = word.size() - 1;
        while (i < j) {
            if (word[i] != word[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void dfs(int i, string s, vector<string> &sofar) {
        if (i == s.size()) {
            output.push_back(sofar);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            string word = s.substr(i, j - i + 1);
            if (isPalindrome(word)) {
                sofar.push_back(word);
                dfs(j + 1, s, sofar);
                sofar.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        dfs(0, s, sofar);
        return output;
    }
};
