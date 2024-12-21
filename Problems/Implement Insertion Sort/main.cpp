void insertionSort(vector<int> &arr) {
    int length = arr.size();
	for (int i = 1; i < length; i++) {
		int num = arr[i];
		int prev = i - 1;
		
		while (prev >= 0 && arr[prev] > num) {
			arr[prev + 1] = arr[prev];
			--prev;
		}
		arr[prev + 1] = num;
	}
}
