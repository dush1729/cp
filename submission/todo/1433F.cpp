//https://codeforces.com/contest/1433/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0;

int getm(int x, int mod) {
	x %= mod;
	if(x < 0) x += mod;
	return x;
}

pair <vector <int>, vector <int>> f(vector <int> &a, int mod) {
	int n = a.size();
	vector dp(n + 1, vector ((n / 2) + 1, vector (mod, 0)));
	vector ok(n + 1, vector ((n / 2) + 1, vector (mod, 0)));
	ok[0][0][0] = 1;
	for(int i = 1; i <= n; i++) {
		int x = a[i - 1];
		for(int k = 0; k <= n / 2; k++) {
			for(int j = 0; j < mod; j++) {
				dp[i][k][j] = max(dp[i][k][j], dp[i - 1][k][j]);
				if(ok[i - 1][k][j]) ok[i][k][j] = 1;
				if(k && ok[i - 1][k - 1][getm(j - x, mod)]) {
					dp[i][k][j] = max(dp[i][k][j], dp[i - 1][k - 1][getm(j - x, mod)] + x);
					ok[i][k][j] = 1;
				}
			}
		}
	}
	return {dp[n][n / 2], ok[n][n / 2]};
}

void run_test(int testcase) {
	int n, m, mod;
	cin >> n >> m >> mod;
	vector dp(n + 1, vector (mod, 0));
	for(int i = 1; i <= n; i++) {
		vector a(m, 0);
		for(int &x: a) cin >> x;

		auto [v, ok] = f(a, mod);
		for(int &x: v) cout << x << " ";cout << endl;
		for(int prev = 0; prev < mod; prev++) {
			for(int curr = 0; curr < mod; curr++) {
				if(!ok[curr]) continue;
				dp[i][getm(prev + curr, mod)] = max(dp[i][getm(prev + curr, mod)], dp[i - 1][prev] + v[curr]);
			}
		}
	}

	cout << endl;
	for(auto &a: dp) {
		for(int &x: a) cout << x << " ";
		cout << endl;
	}

	cout << dp[n][0];
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