class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (!mat[i][j])
                    q.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }
        int rowDirection[4] = {-1, 1, 0, 0};
        int colDirection[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int u = 0; u < 4; u++) {
                int i = node.first + rowDirection[u];
                int j = node.second + colDirection[u];
                if (i >= 0 and j >= 0 and i < mat.size() and j < mat[0].size()) {
                    if (mat[i][j] == -1) {
                        mat[i][j] = mat[node.first][node.second] + 1;
                        q.push({i, j});
                    }
                }
            }
        }
        return mat;
    }
};
