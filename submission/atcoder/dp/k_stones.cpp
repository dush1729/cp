#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n, k;
	cin >> n >> k;
	vector a(n, 0);
	for(int &x: a) cin >> x;

	vector dp(k + 1, 0);
	for(int i = 1; i <= k; i++) {
		for(int &x: a) {
			if(x > i) break;
			if(dp[i - x] == 0) {
				dp[i] = 1;
				break;
			}
		}
	}
	cout << (dp.back() ? "First" : "Second");
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