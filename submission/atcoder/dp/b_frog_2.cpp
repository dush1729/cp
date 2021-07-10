#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector a(n, 0), dp(n, 0);
	for(int &x: a) cin >> x;
	for(int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + abs(a[i - 1] - a[i]);
		for(int j = i - 2; i - j <= k && j >= 0; j--) {
			dp[i] = min(dp[i], dp[j] + abs(a[j] - a[i]));
		}
	}
	cout << dp.back();
}