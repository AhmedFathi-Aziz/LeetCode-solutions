void merge(int l, int mid, int h, vector<int> &a) {
	int len1 = mid - l + 1;
	int len2 = h - mid;
	vector<int> left(len1);
	vector<int> right(len2);
	for (int i = 0; i < len1; i++)
		left[i] = a[i + l];
	for (int i = 0; i < len2; i++)
		right[i] = a[i + mid + 1];
	int i = 0;
	int j = 0;
	int index = l;
	while (i < len1 && j < len2) {
		if (left[i] <= right[j]) {
			a[index++] = left[i++];
		} else {
			a[index++] = right[j++];
		}
	}
	while (i < len1)
		a[index++] = left[i++];
	while (j < len2)
		a[index++] = right[j++];
}

void mergesort(int l, int h, vector<int> &a) {
	if (l < h) {
		int mid = l + (h - l) / 2;
		mergesort(l, mid, a);
		mergesort(mid + 1, h, a);
		::merge(l, mid, h, a);
	}
}

void mergeSort(vector<int> &arr) {
    mergesort(0, arr.size() - 1, arr);
}
