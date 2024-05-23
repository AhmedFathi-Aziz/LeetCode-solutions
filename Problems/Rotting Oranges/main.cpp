class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        int dir[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int minutes = 0;
        while (!q.empty() and freshOranges) {
            int n = q.size();
            bool flag = false;
            while (n--) {
                auto cell = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int row = cell.first + dir[i][0];
                    int col = cell.second + dir[i][1];
                    if (row < 0 || row == grid.size() || col < 0 || col == grid[0].size() || grid[row][col] != 1)
                        continue;
                    q.push({row, col});
                    grid[row][col] = 2;
                    --freshOranges;
                    
                }
            }
            minutes++;
        }
        return freshOranges ? -1 : minutes;
    }
};
