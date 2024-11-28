class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10001, 1e5);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) 
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        if (dp[amount] == 1e5)
            return -1;
        return dp[amount];
    }
};
