#include <bits/stdc++.h>
using namespace std;

int output;
int node;
vector<vector<int>> adj;
void dfs(int root, int parent, int diameter) {
    if (diameter > output) {
        output = diameter;
        node = root;
    }
    for (int u : adj[root]) {
        if (u != parent) {
            dfs(u, root, diameter + 1);
        }
    }
}

void doWork() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    dfs(node, 0, 0);
    cout << output << endl;
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
