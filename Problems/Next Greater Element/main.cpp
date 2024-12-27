vector<int> getNextGreaterElement (vector<int> &A) {
	stack<int> stack;
	for (int i = 0; i < (int) A.size(); i++) {
		while (!stack.empty() && A[i] > A[stack.top()]) {
			A[stack.top()] = A[i];
			stack.pop();
		}
		stack.push(i);
	}
	while (!stack.empty()) {
		A[stack.top()] = -1;
		stack.pop();
	}
	return A;
}
