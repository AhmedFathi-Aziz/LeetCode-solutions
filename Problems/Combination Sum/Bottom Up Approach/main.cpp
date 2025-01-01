class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for (int num : candidates) {
            for (int i = 1; i <= target; i++) {
                if (i < num)
                    continue;
                if (dp[i - num].empty())
                    continue;
                
                for (auto vec : dp[i - num]) {
                    vec.push_back(num);
                    dp[i].push_back(vec);
                }
            }
        }
        return dp[target];
    }
};
