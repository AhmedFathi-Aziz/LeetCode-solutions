class Solution {
public:
    bool dfs(int root, vector<int> &visit, vector<vector<int>> &adj) {
        if (visit[root] == 1)
            return false;
        visit[root] = 1;
        for (auto node : adj[root]) {
            if (visit[node] != 2)
                if (!dfs(node, visit, adj))
                    return false;
        }
        visit[root] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visit(2001, 0);
        vector<vector<int>> adj(2001);
        for (auto vec : prerequisites)
            adj[vec[0]].push_back(vec[1]);
        for (int i = 0; i < numCourses; i++) {
            if (!visit[i]) {
                if (!dfs(i, visit, adj))
                    return false;
            }
        }
        return true;
    }
};
