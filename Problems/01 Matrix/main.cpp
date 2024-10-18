class Solution {
private:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int i = 0;
        int j = 0;
        for (i = 0; i < mat.size(); i++)
            for (j = 0; j < mat[i].size(); j++) {
                if (!mat[i][j])
                    q.push({i, j});
                else
                    mat[i][j] = -1;
            }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int c = 0; c < 4; c++) {
                i = node.first + direction[c].first;
                j = node.second + direction[c].second;
                if (valid(i, j, mat.size(), mat[0].size()))
                    if (mat[i][j] == -1) {
                        mat[i][j] = mat[node.first][node.second] + 1;
                        q.push({i, j});
                    }
            }
        }
        return mat;
    }
};
