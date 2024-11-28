class Solution {
public:
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(int i, int j, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto it : direction) {
                int r = it.first + node.first;
                int c = it.second + node.second;
                if (r < 0 || c < 0 || r == grid.size() || c == grid[0].size() || grid[r][c] != '1')
                    continue;
                grid[r][c] = '0';
                q.push({r, c});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    ++islands;
                }
            }
        }
        return islands;
    }
};
