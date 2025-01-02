class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            for (string word : wordDict) {
                int m = word.size();
                if (i + m <= n && s.substr(i, m) == word) {
                    dp[i] = dp[i + m];
                }
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }
};
