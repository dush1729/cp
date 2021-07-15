#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 1, N = 1001, M = 22, K = 80, MAX = 1e9;

int oxy, nit, n;
int x[N], y[N], w[N], dp[N][M][K], cache[N][M][K];

int f(int n, int oxy, int nit) {
	if(max(oxy, nit) <= 0) return 0;
	oxy = max(0, oxy), nit = max(0, nit);
	if(n == -1) return MAX;

	int &ans = dp[n][oxy][nit];
	if(cache[n][oxy][nit]) return ans;
	cache[n][oxy][nit] = 1;

	ans = min(f(n - 1, oxy, nit), f(n - 1, oxy - x[n], nit - y[n]) + w[n]);
	return ans;
}

void run_test(int testcase) {
	cin >> oxy >> nit >> n;
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> w[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < M; j++)
			for(int k = 0; k < K; k++) cache[i][j][k] = 0, dp[i][j][k] = MAX;

	int ans = MAX;
	for(int i = oxy; i < M; i++) {
		for(int j = nit; j < K; j++) {
			ans = min(ans, f(n - 1, i, j));
		}
	}
	cout << ans << "\n";
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