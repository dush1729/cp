#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n;
	cin >> n;
	vector a(n, vector(3, 0));
	for(auto &v: a) {
		for(int &x: v) cin >> x;
	}
	auto dp = a;
	for(int i = 1; i < n; i++) {
		for(int curr = 0; curr < 3; curr++) {
			for(int pv = 0; pv < 3; pv++) {
				if(pv == curr) continue;
				dp[i][curr] = max(dp[i][curr], dp[i - 1][pv] + a[i][curr]);
			}
		}
	}
	cout << *max_element(dp.back().begin(), dp.back().end());
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