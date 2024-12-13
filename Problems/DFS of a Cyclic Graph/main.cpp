vector<int> output;

void dfsUtil(int node, vector<vector<int>> &adjList, vector<bool> &visit) {
	if (visit[node])
		return;
	visit[node] = true;
	output.push_back(node);
	for (int i : adjList[node])
		dfsUtil(i, adjList, visit);
}

vector<int> dfs(vector<vector<int>> &adjList) {
	output.clear();
    int n = adjList.size();
	vector<bool> visit(n, false);
	dfsUtil(0, adjList, visit);
	return output;
}
