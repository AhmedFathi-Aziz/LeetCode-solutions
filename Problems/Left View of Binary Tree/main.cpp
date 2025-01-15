vector<int> leftView(Node* root) {
	if (root == nullptr)
		return {};
    queue<Node*> q;
	q.push(root);
	vector<int> output;
	output.reserve(1e5);
	while (!q.empty()) {
		int n = q.size();
		Node *node;
		while (n--) {
			node = q.front();
			q.pop();
			if (node->right)
				q.push(node->right);
			if (node->left)
				q.push(node->left);
		}
		output.emplace_back(node->data);
	}
	return output;
}
