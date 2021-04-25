#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 5e3 + 20;

int n, a[N];

int sgn(int x) {return x > 0;}

void run_test(int testcase) {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];

	vector <int> dp(n, 1);
	int ans = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(abs(a[j]) < abs(a[i]) && sgn(a[i]) != sgn(a[j])) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	#ifndef LOCAL
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);

	int t = 1;
	if(areTests) cin >> t;
	for(int i = 1; i <= t; i++) {
		run_test(i);
	}
}