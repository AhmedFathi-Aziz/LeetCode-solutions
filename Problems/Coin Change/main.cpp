class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e5);
        dp[0] = 0;

        int i = 1;
        for (; i <= amount; i++)
            for (auto &coin : coins)
                if (i - coin >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
       
        if (dp[amount] == 1e5)
            return -1;
        return dp[amount];
    }
};

// Bottom-Up approach
