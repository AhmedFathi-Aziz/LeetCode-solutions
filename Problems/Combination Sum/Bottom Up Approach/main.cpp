class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for (int j : candidates) {
            for (int i = 1; i <= target; i++) {
                if (i < j)
                    continue;
                if (dp[i - j].empty())
                    continue;
                for (auto u : dp[i - j]) {
                    u.push_back(j);
                    dp[i].push_back(u);
                }
            }
        }
        return dp[target];
    }
};
