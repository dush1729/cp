#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 20, MOD = 1e9 + 7;

int n, dp[N];

int power(int a, int b) {
	if(b == 0) return 1;
	int ans = power(a, b >> 1);
	ans = (1ll * ans * ans) % MOD;
	if(b & 1) ans = (1ll * ans * a) % MOD;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int s = n * (n + 1) / 2;
	if(s % 2) {
		s >> = 1;
	} else {
		s >>= 1;
	}

	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = s; j >= i; j--) {
			dp[j] += dp[j - i];
			dp[j] %= MOD;
		}
	}

	cout << (1ll * dp[s] * power(2, MOD - 2)) % MOD;
}