#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1001);

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> dis(n + 1, -1);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int parent = q.front();
        q.pop();
        for (int &child : edges[parent]) {
            if (dis[child] == -1) {
                dis[child] = dis[parent] + 6;
                q.push(child);
            }
        }
    }
    return dis;
}

int main()
{
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        while (m--) {   
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int root;
        cin >> root;
        vector<int> dis = bfs(n, m, adj, root);
        for (int i = 1; i <= n; i++) {
            if (i != root) {
                cout << dis[i] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}

