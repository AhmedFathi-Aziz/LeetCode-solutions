class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10001, 10001);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j : coins) {
                if (i >= j)
                    dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
        if (dp[amount] != 10001)
            return dp[amount];
        return -1;
    }
};
