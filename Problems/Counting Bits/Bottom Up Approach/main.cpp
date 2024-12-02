class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        int number = 1;
        for (int i = 1; i <= n; i++) {
            if (2 * number == i) {
                number = i;
                dp[i] = 1;
            } else {
                dp[i] = dp[i - number] + 1;
            }
        }
        return dp;
    }
};
