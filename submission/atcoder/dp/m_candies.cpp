#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, MOD = 1e9 + 7, N = 1e2 + 1, K = 1e5 + 1;

int n, k, a[N], dp[N][K], pre[K];

void run_test(int testcase) {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];

	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		pre[0] = 1;
		for(int j = 1; j <= k; j++) {
			pre[j] = pre[j - 1] + dp[i - 1][j];
			pre[j] %= MOD;
		}

		for(int j = 0; j <= k; j++) {
			dp[i][j] = pre[j];
			if(j - a[i] > 0) dp[i][j] -= pre[j - a[i] - 1];
			if(dp[i][j] < 0) dp[i][j] += MOD;
		}
	}

	cout << dp[n][k];
}

int main() {
	ios::sync_with_stdio(0);
	#ifndef DUSH1729
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);

	int t = 1;
	if(areTests) cin >> t;
	for(int i = 1; i <= t; i++) {
		run_test(i);
	}
}