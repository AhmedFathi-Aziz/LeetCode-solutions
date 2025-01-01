bool canGetCheese(vector<vector<int> > &maze) {
	int n = maze.size();
	int m = maze[0].size();
    bool dp[n][m];
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j]) {
				if (i)
					if (dp[i - 1][j])
						dp[i][j] = true;
				if (j)
					if (dp[i][j - 1])
						dp[i][j] = true;
			}
		}
	}
	return dp[n - 1][m - 1];
}
