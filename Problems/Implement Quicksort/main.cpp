int partition(int l, int h, vector<int> &a) {
	int pivot = a[l];
	int index = l;
	while (l < h) {
		while (l < h && a[h] > pivot)
			h--;
		while (l < h && a[l] <= pivot)
			l++;
		if (l < h)
			swap(a[l], a[h]);
	}
	swap(a[index], a[h]);
	return h;
}

void quicksort(int l, int h, vector<int> &a) {
	if (l < h) {
		int index = partition(l, h, a);
		quicksort(l, index - 1, a);
		quicksort(index + 1, h, a);
	}
}

void quickSort(vector<int> &arr) {
	   quicksort(0, arr.size() - 1, arr);
}
