class Solution { 
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (auto &direction : directions) {
                int r = row + direction.first;
                int c = col + direction.second;
                if (r >= 0 and c >= 0 and r < grid.size() &&
                    c < grid[0].size() && grid[r][c] == '1')
                    q.push({r, c}),
                    grid[r][c] = '0';
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
