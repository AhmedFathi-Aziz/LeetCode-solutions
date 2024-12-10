class Solution {
public:
    bool dfs(string s, int index, unordered_set<string> &dict, vector<int> &memo) {
        if (index == s.size())
            return true;
        int &ret = memo[index];
        if (~ret)
            return ret;
        for (int i = index; i < s.size(); i++) {
            string sub = s.substr(index, i - index + 1);
            auto it = dict.find(sub);
            if (it != dict.end() && dfs(s, i + 1, dict, memo))
                return ret = true;
        }
        return ret = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string word : wordDict)
            dict.insert(word);
        vector<int> memo(301, -1);
        return dfs(s, 0, dict, memo);
    }
};
