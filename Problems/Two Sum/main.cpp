pair<int,int> twoSum(vector<int> &A, int target) {
	unordered_map<int, int> mp;
	pair<int, int> output;
	for (int i = 0; i < (int) A.size(); i++) {
		int diff = target - A[i];
		if (mp.find(diff) != mp.end()) {
			output =  {i, mp[diff]};
			break;
		}
		mp[A[i]] = i;
	}
	return output;
}
