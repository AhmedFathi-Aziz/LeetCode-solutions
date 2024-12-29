#include <bits/stdc++.h>
using namespace std;

int output[200009];

void dfs(vector<vector<int>> &adj, int node) {
    output[node] = 1;
    for (int i : adj[node]) {
        dfs(adj, i);
        output[node] += output[i];
    }
    
}

void doWork() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        adj[v].push_back(u);
    }
    
    dfs(adj, 1);
    for (int i = 1; i <= n; i++) {
        cout << output[i] - 1 << ' ';
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
