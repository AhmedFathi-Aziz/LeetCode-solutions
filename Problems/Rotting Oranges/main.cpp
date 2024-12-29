class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int sofar = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j]) {
                    sofar++;
                }
            }
        }
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int output = 0;
        while (!q.empty() && sofar) {
            int len = q.size();
            while (len-- && sofar) {
                auto cell = q.front();
                q.pop();
                for (auto d : dir) {
                    int r = cell.first + d[0];
                    int c = cell.second + d[1];
                    if (r < 0 || c < 0 || r == grid.size() 
                        || c == grid[r].size() || grid[r][c] != 1) {
                        continue;
                    }
                    grid[r][c] = 2;
                    q.push({r, c});
                    sofar--;
                }
            }
            output++;
        }
        if (sofar)
            return -1;
        return output;
    }
};
