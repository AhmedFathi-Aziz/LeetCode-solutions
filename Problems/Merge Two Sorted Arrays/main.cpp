vector<int> mergeSortedArrays(vector<int> &A, vector<int> B) {
    int n = A.size();
	int m = B.size();
	vector<int> output(n + m);
	int i = 0;
	int j = 0;
	int in = 0;
	while (i < n && j < m) {
		if (A[i] <= B[j])
			output[in++] = A[i++];
		else
			output[in++] = B[j++];
	}
	while (i < n)
		output[in++] = A[i++];
	while (j < m)
		output[in++] = B[j++];
	return output;
}
