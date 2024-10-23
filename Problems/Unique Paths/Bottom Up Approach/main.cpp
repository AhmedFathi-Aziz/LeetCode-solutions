class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(101, vector<int> (101, 0));
        dp[0][0] = 1;
        int number = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                number = 0;
                if (j)
                    number = dp[i][j - 1];
                if (i)
                    number += dp[i - 1][j];
                dp[i][j] = number;
            }
        }
        return dp[m - 1][n - 1];
    }
};
