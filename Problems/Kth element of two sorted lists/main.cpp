int doWork(vector<int> &num1, vector<int> &num2, int l1, int l2, int h1, int h2, int k) {
	if (l1 > h1)
		return num2[l2 + k - 1];
	if (l2 > h2) 
		return num1[l1 + k - 1];
	int mid1 = (l1 + h1) / 2;
	int mid2 = (l2 + h2) / 2;
	
	int len = (mid1 - l1 + 1) + (mid2 - l2 + 1);
	if (len <= k) {
		if (num1[mid1] < num2[mid2]) {
			return doWork(num1, num2, mid1 + 1, l2, h1, h2, k - (mid1 - l1 + 1));
		} else {
			return doWork(num1, num2, l1, mid2 + 1, h1, h2, k - (mid2 - l2 + 1));
		}
	} else {
		if (num1[mid1] > num2[mid2])
			return doWork(num1, num2, l1, l2, mid1 - 1, h2, k);
		else
			return doWork(num1, num2, l1, l2, h1, mid2 - 1, k);
	}
}

int getKthElement(vector<int> &firstArr, vector<int> &secondArr, int k) {
	return doWork(firstArr, secondArr, 0, 0, firstArr.size() - 1, secondArr.size() - 1, k);
}
