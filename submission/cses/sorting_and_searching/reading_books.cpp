#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;



void run_test(int testcase) {
	ll n, s = 0, mx = 0;
	cin >> n;
	vector a(n, 0ll);
	for(ll &x: a) cin >> x, s += x, mx = max(mx, x);

	cout << max(2 * mx, s) << "\n";
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