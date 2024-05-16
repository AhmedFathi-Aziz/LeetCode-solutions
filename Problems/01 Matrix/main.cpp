class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return i < n && j < m && i >= 0 && j >= 0;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, -1, 1};
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j])
                    q.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int newI = i + r[k];
                int newJ = j + c[k];
                if (valid(newI, newJ, n, m)) {
                    if (mat[newI][newJ] == -1)
                        mat[newI][newJ] = mat[i][j] + 1,
                        q.push({newI, newJ});
                }
            }
        }
        return mat;
    }
};
