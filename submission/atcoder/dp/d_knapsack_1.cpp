#include "bits/stdc++.h"
using namespace std;


int main() {
	int n, capacity, w, v;
	long long ans = 0;
	cin >> n >> capacity;
	vector dp(capacity + 1, 0LL);
	while(n--) {
		cin >> w >> v;
		for(int i = capacity; i >= w; i--) {
			dp[i] = max(dp[i], dp[i - w] + v);
			ans = max(ans, dp[i]);
		}
	}

	cout << ans;
}