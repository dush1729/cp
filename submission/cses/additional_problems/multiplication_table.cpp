#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	ll n;
	cin >> n;

	ll lo = 1, hi = n * n, ans = -1;
	while(lo <= hi) {
		ll mid = (lo + hi) >> 1, ele = n * n / 2 + 1;

		for(int i = 1; i <= n; i++) {
			ele -= min(n, mid / i);
			if(ele <= 0) break;
		}

		if(ele <= 0) hi = mid - 1, ans = mid;
		else lo = mid + 1;
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