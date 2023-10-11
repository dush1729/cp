#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, MOD = 1e9 + 7;

void add(int &x, int y) {x = (x + y) % MOD;}

void run_test(int testcase) {
	int n;
	string a;
	cin >> n >> a;

	vector dp(n + 1, vector (n + 1, 0));
	dp[1][1] = 1;
	for(int len = 2; len <= n; len++) {
		for(int i = 1; i <= len; i++) add(dp[len - 1][i], dp[len - 1][i - 1]);
		for(int num = 1; num <= len; num++) {
			int l = 1, r = num - 1;
			if(a[len - 2] == '<') l = num, r = len - 1;
			add(dp[len][num], (dp[len - 1][r] - dp[len - 1][l - 1] + MOD) % MOD);
		}
	}

	int ans = 0;
	for(int num = 1; num <= n; num++) add(ans, dp[n][num]);
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