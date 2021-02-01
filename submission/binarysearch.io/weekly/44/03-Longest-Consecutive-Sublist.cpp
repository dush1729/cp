int solve(vector<int>& a) {
	int n = a.size(), ans = 0;
	for(int i = 0; i < n; i++) {
		int mn = INT_MAX, mx = INT_MIN;
		for(int j = i; j < n; j++) {
			mn = min(mn, a[j]);
			mx = max(mx, a[j]);
			if(mx - mn + 1 == j - i + 1) {
				ans = max(ans, mx - mn + 1);
			}
		}
	}
	return ans;
}
