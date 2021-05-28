#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 2e5 + 20;

int n, a[N];

void run_test(int testcase) {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);
	ll r = 0;
	for(int i = 0; i < n; ) {
		if(a[i] <= r + 1) r += a[i++];
		else break;
	}
	cout << r + 1;
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