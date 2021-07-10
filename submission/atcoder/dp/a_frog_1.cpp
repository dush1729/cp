#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector a(n, 0), dp(n, 0);
	for(int &x: a) cin >> x;
	for(int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + abs(a[i - 1] - a[i]);
		if(i > 1) dp[i] = min(dp[i], dp[i - 2] + abs(a[i - 2] - a[i]));
	}
	cout << dp.back();
}