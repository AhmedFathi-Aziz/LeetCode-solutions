#include <bits/stdc++.h>
using namespace std;

int dis[200001];
void dfs(int root, vector<vector<int>> &adj) {
    dis[root] = 1;
    for (int node : adj[root]) {
        dfs(node, adj);
        dis[root] += dis[node];
    }
}

void doWork() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 9);
    for (int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        adj[v].push_back(u);
    }
    dfs(1, adj);
    for (int i = 1; i <= n; i++) {
        cout << --dis[i] << ' ';
    }
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
