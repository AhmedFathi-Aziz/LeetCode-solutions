vector<int> distintNumbersInWindow(vector<int> &A, int k) {
    unordered_map<int, int> mp;
	int j = 0;
	while (j < k)
		mp[A[j++]]++;
	vector<int> output;
	output.push_back(mp.size());
	while (j < A.size()) {
		mp[A[j]]++;
		mp[A[j - k]]--;
		if (mp[A[j - k]] == 0)
			mp.erase(A[j - k]);
		j++;
		output.push_back(mp.size());
	}
	return output;
}
