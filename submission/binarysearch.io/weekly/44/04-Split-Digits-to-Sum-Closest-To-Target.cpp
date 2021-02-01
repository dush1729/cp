const int N = 1e3 + 20, M = 1e4 + 20;
#define ll long long

ll dp[N][M];

ll f(int i, string &a, int t, int s) {
	if(s >= M) return INT_MAX;
	if(dp[i][s] != -1) return dp[i][s];

	if(i == a.size()) {
		return dp[i][s] = abs(s - t);
	}

	ll val = 0, ans = INT_MAX;
	for(int j = i; j < a.size() && j - i < 4; j++) {
		val = val * 10 + a[j] - '0';
		ans = min(ans, f(j + 1, a, t, s + val));
	}
	return dp[i][s] = ans;
}

int solve(string s, int target) {
	for(int i = 0; i <= s.size(); i++) {
		for(int j = 0; j < M; j++) {
			dp[i][j] = -1;
		}
	}

	return f(0, s, target, 0);
}
