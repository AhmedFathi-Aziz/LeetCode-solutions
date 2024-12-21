int largestContiguousSum(vector <int> &arr){
    int length = arr.size();
	int output = arr[0];
	int current = 0;
	for (int i = 0; i < length; i++) {
		if (current < 0) {
			current = 0;
		}
		current += arr[i];
		output = max(output, current);
	}
	return output;
}
