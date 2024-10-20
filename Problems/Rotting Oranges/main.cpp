class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        int time = 0;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    ++fresh;
            }
        }
        while (!q.empty() and fresh) {
            int n = q.size();
            while (n--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (auto &d : direction) {
                    int r = d.first + row;
                    int c = d.second + col;
                    if (r < 0 or r == grid.size() or
                        c < 0 or c == grid[r].size() or grid[r][c] != 1)
                        continue;
                    grid[r][c] = 2,
                    q.push({r, c}),
                    --fresh;
                }
            }
            ++time;
        }
        if (fresh)
            return -1;
        return time;
    }
};
