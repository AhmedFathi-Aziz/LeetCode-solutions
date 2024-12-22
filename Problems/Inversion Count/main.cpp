void merge(int l, int mid, int h, vector<int> &a, int &output) {
	int len1 = mid - l + 1;
	int len2 = h - mid;
	
	vector<int> left(len1);
	vector<int> right(len2);
	for (int i = 0; i < len1; i++)
		left[i] = a[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = a[mid + 1 + i];
	int i = 0;
	int j = 0;
	int index = l;
	while (i < len1 && j < len2) {
		if (left[i] <= right[j]) {
			a[index++] = left[i++];
		} else {
			output += (len1 - i);
			a[index++] = right[j++];
		}
	}
	while (i < len1)
		a[index++] = left[i++];
	
	while (j < len2) {
		a[index++] = right[j++];
	}
}

void mergeSort(int l, int h, vector<int> &a, int &output) {
	if (l < h) {
		int mid = (l + h) / 2;
		mergeSort(l, mid, a, output);
		mergeSort(mid + 1, h, a, output);
		::merge(l, mid, h, a, output);
	}
}

int getInversionCount(vector<int> &array) {
	int output = 0;
	mergeSort(0, array.size() - 1, array, output);
	return output;
}

