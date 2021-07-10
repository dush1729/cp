#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, MOD = 1e9 + 7;
const char BLOCKED = '#';


void run_test(int testcase) {
	int n, m;
	cin >> n >> m;
	vector <string> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	vector dp(n, vector (m, 0));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == BLOCKED) continue;
			if(i > 0) dp[i][j] += dp[i - 1][j];
			if(j > 0) dp[i][j] += dp[i][j - 1];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n - 1][m - 1];
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