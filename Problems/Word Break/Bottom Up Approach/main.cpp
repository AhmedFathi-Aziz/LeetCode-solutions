class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (string word : wordDict) {
            set.insert(word);
        }

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (!dp[i])
                continue;
            for (int j = i; j < n; j++) {
                string word = s.substr(i, j - i + 1);
                if (set.find(word) != set.end())
                    dp[j + 1] = true;
            }
        }
        return dp[n];
    }
};
