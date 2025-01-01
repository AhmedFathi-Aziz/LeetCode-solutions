int longestSubarrayWithZeroSum(vector<int> &A) {
    unordered_map<int, int> mp;
	int output = 0,
	sum = 0;
	for (int i = 0; i < (int) A.size(); i++) {
		sum += A[i];
		if (sum == 0)
			output = i + 1;
		if (mp.find(sum) != mp.end()) {
			output = max(output, i - mp[sum]);
		} else {
			mp[sum] = i;
		}
	}
	return output;
}
