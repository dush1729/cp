#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n, k;
	cin >> n >> k;
	vector a(n, 0);
	for(int &x: a) cin >> x;
	sort(a.begin(), a.end());

	ll lo = 1, hi = 1e18, ans = -1;
	while(lo <= hi) {
		ll mid = (lo + hi) >> 1, products = 0;
		for(int &x: a) {
			products += mid / x;
			if(products >= k) break;
		}

		if(products >= k) hi = mid - 1, ans = mid;
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