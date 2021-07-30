#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 3e3 + 2;

int n, a[N], cache[N][N];
ll dp[N][N];

ll f(int l, int r) {
	ll &ans = dp[l][r];
	if(cache[l][r]) return ans;
	cache[l][r] = 1;

	ans = LLONG_MIN;
	int p = (l + n - 1 - r) % 2;
	if(l == r) {
		ans = (p == 0 ? a[l] : -a[l]);
	} else {
		if(p == 0) ans = max(a[l] + f(l + 1, r), a[r] + f(l, r - 1));
		else ans = min(-a[l] + f(l + 1, r), -a[r] + f(l, r - 1));
	}
	return ans;
}

void run_test(int testcase) {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];

	cout << f(0, n - 1);
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