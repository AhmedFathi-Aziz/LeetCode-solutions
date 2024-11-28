class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        dp[0][0] = 1;
        int sofar = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i and !j)
                    continue;
                sofar = 0;
                if (j)
                    sofar += dp[i][j - 1];
                if (i)
                    sofar += dp[i - 1][j];
                dp[i][j] = sofar;
            }
        }
        return dp[m - 1][n - 1];
    }
};
