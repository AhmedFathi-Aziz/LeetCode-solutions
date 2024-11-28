class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &memo) {
        if (i < 0 || j < 0)
            return 0;
        if (!i && !j)
            return 1;
        int &ret = memo[i][j];
        if (~ret)
            return ret;
        return ret = dfs(i - 1, j, memo) + dfs(i, j - 1, memo);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int> (n, -1));
        return dfs(m - 1, n - 1, memo);
    }
};
