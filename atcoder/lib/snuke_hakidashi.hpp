// Hakidashi ho
	int r = 0;
	vector<int> top(n);
	for (int i = 60; i >= 0; --i) {
		int j = r;
		for (; j < n; ++j) {
			if (a[j]>>i&1) {
				swap(a[r],a[j]);
				break;
			}
		}
		if (j == n) continue;
		top[r] = i;
		rep(k,n) {
			if (r == k) continue;
			if (a[k]>>i&1) a[k] ^= a[r];
		}
		++r;
	}
//
