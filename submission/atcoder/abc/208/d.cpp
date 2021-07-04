#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 420, MAX = 1e9;

int dp[N][N];

void run_test(int testcase) {
	int n, m, u, v, c;
	ll ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(j != i) {
				dp[i][j] = MAX;
			}
		}
	}
	for(int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		dp[u][v] = c;
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				if(dp[i][j] != MAX) ans += dp[i][j];
			}
		}
	}
	cout << ans;
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