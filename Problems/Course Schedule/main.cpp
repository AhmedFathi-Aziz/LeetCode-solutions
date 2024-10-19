class Solution {
private:
    bool dfs(int node, vector<bool> &visit, vector<vector<int>> &adj) {
        if (visit[node])
            return false;
        if (!adj[node].size())
            true;
        visit[node] = true;
        for (int i : adj[node]) {
            if (!dfs(i, visit, adj))
                return false;
        }
        visit[node] = 0;
        adj[node] = {};
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visit(numCourses, 0);
        for (auto &vec : prerequisites)
            adj[vec[0]].push_back(vec[1]);
        int i = 0;
        for (; i < numCourses; i++)
            if (!dfs(i, visit, adj))
                return false;
        return true;
    }
};
