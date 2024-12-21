vector<vector<int>> threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
	vector<vector<int>> output;
	int length = A.size();
	for (int i = 0; i < length; i++) {
		if (A[i] > 0)
			break;
		if (i && A[i] == A[i - 1])
			continue;
		int l = i + 1;
		int r = length - 1;
		while (l < r) {
			int threesum = A[i] + A[l] + A[r];
			if (threesum > 0)
				--r;
			else if (threesum < 0)
				++l;
			else {
				output.push_back({A[i], A[l], A[r]});
				++l;
				while (l < r && A[l] == A[l - 1])
					++l;
			}
		}
	}
	return output;
}
