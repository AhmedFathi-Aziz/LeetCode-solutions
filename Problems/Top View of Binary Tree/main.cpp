struct Buffer {
	Node *node;
	int col;
};

vector<int> topView(Node* root) {
	queue<Buffer> q;
	q.push({root, 0});
	map<int, int> mp;
	while (!q.empty()) {
		auto current = q.front();
		q.pop();
		
		if (mp.find(current.col) == mp.end())
			mp[current.col] = current.node->data;
		if (current.node->left)
			q.push({current.node->left, current.col - 1});
		if (current.node->right)
			q.push({current.node->right, current.col + 1});
	}
	vector<int> output;
	for (auto &[col, val] : mp)
		output.push_back(val);
	return output;
}
