class Solution {

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        std::function<int(int, int)> paths = [&](int i, int j) -> int {
            if (i == 0 && j == 0)
                return 1;
            if (i < 0 || i == m || j < 0 || j == n)
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            return dp[i][j] = paths(i - 1, j) + paths(i, j - 1);
        };
        return paths(m - 1, n - 1);
    }
};

// top-down approach
