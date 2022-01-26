#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0, N = 1e4 + 1, D = 10, M = 100, MOD = 1e9 + 7;

string a;
int mod, dp[N][D][M][2], cache[N][D][M][2];

int f(int i, int d, int m, int strict) {
	if(i + 1 == a.size()) return (m + d) % mod == 0;

	int &ans = dp[i][d][m][strict];
	if(cache[i][d][m][strict]) return ans;
	cache[i][d][m][strict] = 1;

	if(strict) {
		for(int nd = 0; nd < a[i + 1] - '0'; nd++) {
			ans = (ans + f(i + 1, nd, (m + d) % mod, 0)) % MOD;
		}
		ans = (ans + f(i + 1, a[i + 1] - '0', (m + d) % mod, 1)) % MOD;
	} else {
		for(int nd = 0; nd < D; nd++) {
			ans = (ans + f(i + 1, nd, (m + d) % mod, 0)) % MOD;
		}
	}
	return ans;
}

void run_test(int testcase) {
	cin >> a >> mod;

	int ans = 0;
	for(int d = 0; d < a[0] - '0'; d++) {
		ans = (ans + f(0, d, 0, 0)) % MOD;
	}
	ans = (ans + f(0, a[0] - '0', 0, 1)) % MOD;
	ans = (ans - 1 + MOD) % MOD;
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