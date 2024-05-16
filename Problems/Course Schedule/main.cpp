class Solution {
public:

    bool dfs(vector<vector<int>> &adj, vector<int> &visited, int node) {
        if (visited[node] == 2)
            return false;
        visited[node] = 2;
        for (auto &i : adj[node])
            if (visited[i] != 1)
                if (!dfs(adj, visited, i))
                    return false;
        visited[node] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i])
                if (!dfs(adj, visited, i))
                    return false;
        return true;
    }
};
