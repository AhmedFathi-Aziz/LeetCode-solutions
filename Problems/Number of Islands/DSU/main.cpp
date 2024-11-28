class Solution {
public:
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int parent[100001];
    int group[100001];

    void init() {
        for (int i = 0; i < 100001; i++) {
            parent[i] = i;
            group[i] = 1;
        }
    }

    int root(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = root(parent[node]);
    }

    int Union(int u, int v) {
        int i = root(u);
        int j = root(v);
        if (i == j)
            return 0;
        if (group[i] > group[j])
            swap(i, j);
        group[j] += group[i];
        parent[i] = j;
        return 1;
    }

    int index(int i, int j, int n) {
        return i * n + j;
    }

    int numIslands(vector<vector<char>>& grid) {
        init();
        int out = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    ++out;
                    grid[i][j] = '0';
                    int u = index(i, j, grid[0].size());
                    for (auto dir : direction) {
                        int r = i + dir.first;
                        int c = j + dir.second;
                        if (r < 0 || c < 0 || r == grid.size() || 
                            c == grid[i].size() || grid[r][c] == '0')
                            continue;
                        int v = index(r, c, grid[0].size());
                        out -= Union(u, v);
                    }
                }
            }
        }
        return out;
    }
};
