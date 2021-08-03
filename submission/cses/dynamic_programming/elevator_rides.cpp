#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 20, M = 1 << N;
const ll MAX = 1e14;

void ckmin(ll &x, ll y) {x = min(x, y);}

void run_test(int testcase) {
	int n, w;
	cin >> n >> w;
	vector a(n, 0);
	for(int &x: a) cin >> x;

	vector b(1 << n, 0);
	for(int i = 1; i < (1 << n); i++) b[i] = b[i >> 1] + (i % 2);

	vector dp(1 << n, vector (n + 1, MAX));
	// min weight for given set of people and rides
	dp[0][0] = 0;
	for(int mask = 0; mask < (1 << n); mask++) {
		for(int ride = 0; ride <= b[mask]; ride++) {
			if(dp[mask][ride] == MAX) continue;

			for(int i = 0; i < n; i++) {
				if(mask & (1 << i)) continue;

				if(ride > 0 && dp[mask][ride] + a[i] <= w) {
					ckmin(dp[mask ^ (1 << i)][ride], dp[mask][ride] + a[i]);
				} else {
					ckmin(dp[mask ^ (1 << i)][ride + 1], a[i]);
				}
			}
		}
	}

	for(int rides = 0; ; rides++) {
		if(dp[(1 << n) - 1][rides] != MAX) {
			cout << rides;
			break;
		}
	}
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