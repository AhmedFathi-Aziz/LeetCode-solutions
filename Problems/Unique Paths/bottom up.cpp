class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
	    dp[0][0] = 1;
	
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0)
                    continue;
	        	int value = 0;
		        if (i)
                    value += dp[i - 1][j];
                if (j)
                    value += dp[i][j - 1];
                dp[i][j] = value;
	    	
	        }
        }
        return dp[m - 1][n - 1];
    }
};
// bottom-up approach

