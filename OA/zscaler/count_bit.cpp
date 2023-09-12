long countBit(vector<int> arr, int k) {
	long cnt = 0, n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (__builtin_popcount(arr[i] | arr[j]) + __builtin_popcount(arr[i] & arr[j]) >= k) {
				cnt += 1;
			}
		}
	}

	return cnt;
}