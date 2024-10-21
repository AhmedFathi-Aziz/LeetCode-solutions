class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = { {} };
        for (int i : candidates) {
            for (int j = 1; j <= target; j++) {
                if (j < i)
                    continue;
                if (dp[j - i].empty())
                    continue;

                for (auto combination : dp[j - i]) {
                    combination.push_back(i);
                    dp[j].push_back(combination);
                }
            }
        }
        return dp[target];
    }
};
