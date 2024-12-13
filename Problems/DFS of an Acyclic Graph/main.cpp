vector<int> output;

void preorder(int node, vector<vector<int>> &adjList, vector<bool> visit) {
	if (visit[node])
		return;
	visit[node] = true;
	output.push_back(node);
	for (int i : adjList[node])
		preorder(i, adjList, visit);
}

vector<int> dfs(vector<vector<int>> &adjList) {
	output.clear();
	int n = adjList.size();
   	vector<bool> visit(n, false);
	preorder(0, adjList, visit);
	return output;
}
