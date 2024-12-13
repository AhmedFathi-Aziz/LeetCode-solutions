#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visit) {
   if (visit[node])
      return;
   visit[node] = true;
   for (int i : adj[node])
      dfs(i, adj, visit);
}

int main() {
   int n, e;
   cin >> n >> e;
   vector<vector<int>> adj(n + 1);
   vector<bool> visit(n + 1, 0);
   while (e--) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   int output = 0;
   for (int i = 1; i <= n; i++) {
      if (!visit[i]) {
         ++output;
         dfs(i, adj, visit);
      }
   }
   cout << output;
   return 0;
}

