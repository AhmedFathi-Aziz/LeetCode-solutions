#include <bits/stdc++.h>
using namespace std;

int answer;
bool visited[200009];

void dfs(int node, int root, vector<vector<int>> &adj) {
    for (int u : adj[node]) {
        if (u != root) {
            dfs(u, node, adj);
            if (!visited[u] && !visited[node]) {
                visited[u] = true;
                visited[node] = true;
                answer++;
            }
        }
    }
}

void doWork() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 9);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, adj);
    cout << answer << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ONLINE_JUDGE
#endif

    int cases = 1;
    // cin >> cases;
    while (cases--)
        doWork();
    return 0;
}
