class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        for (auto num : candidates) {
            for (int i = 1; i <= target; i++) {
                if (i < num)
                    continue;
                if (i == num)
                    dp[i].push_back({num});
                else {
                    if (!dp[i - num].empty())
                        for (auto list : dp[i - num]) {
                            list.push_back(num);
                            dp[i].push_back(list);
                        }
                }
            }
        }
        return dp[target];
    }
};
