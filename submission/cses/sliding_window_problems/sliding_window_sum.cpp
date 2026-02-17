#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;



void run_test(int testcase) {
	ll n, k, x, a, b, c;
	cin >> n >> k >> x >> a >> b >> c;

	vector arr(k, 0ll);
	arr[0] = x;
	ll s = x, ans = (k == 1 ? s : 0);
	for(int i = 1; i < n; i++) {
		x = (a * x + b) % c;
		s += x;
		if(i >= k) s -= arr[i % k];
		if(i >= k - 1) ans ^= s;
		arr[i % k] = x;
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