class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if (i < 0 || j < 0 || i == grid.size() ||
            j == grid[i].size() || !grid[i][j])
            return 0;
        grid[i][j] = 0;
        return (1 + dfs(i + 1, j, grid) +
            dfs(i - 1, j, grid) +
            dfs(i, j + 1, grid) +
            dfs(i, j - 1, grid)
        );
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int output = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    output = max(output, dfs(i, j, grid));
                }
            }
        }
        return output;
    }
};
