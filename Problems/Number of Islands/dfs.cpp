class Solution { 
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || 
            j == grid[i].size() || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        for (auto &dir : directions)
            dfs(grid, i + dir.first, j + dir.second);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
