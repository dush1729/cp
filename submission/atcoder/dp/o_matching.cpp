#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, MOD = 1e9 + 7;

void add(int &x, int &y) {x = (x + y) % MOD;}

void run_test(int testcase) {
	int n;
	cin >> n;
	vector a(n, vector (n, 0));
	for(auto &v: a)
		for(int &x: v) cin >> x;

	vector dp(1 << n, 0);
	dp[0] = 1;
	for(int mask = 0; mask + 1 < (1 << n); mask++) {
		int man = __builtin_popcount(mask);
		for(int woman = 0; woman < n; woman++) {
			if(a[man][woman]) add(dp[mask ^ (1 << woman)], dp[mask]); 
		}
	}
	cout << dp[(1 << n) - 1];
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