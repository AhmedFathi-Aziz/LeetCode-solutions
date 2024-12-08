class Solution {
public:
    vector<int> output;
    bool dfs(int i, vector<vector<int>> &adj, vector<int> &visit) {
        if (visit[i] == 1)
            return false;
        if (visit[i] == 2)
            return true;
        visit[i] = 1;
        for (auto node : adj[i])
            if (!dfs(node, adj, visit))
                return false;
        output.push_back(i);
        visit[i] = 2;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visit(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto node : prerequisites)
            adj[node[0]].push_back(node[1]);
        for (int i = 0; i < numCourses; i++)
            if (!dfs(i, adj, visit))
                return {};
        return output;
    }
};
