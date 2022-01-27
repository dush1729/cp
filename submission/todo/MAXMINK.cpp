//https://www.codechef.com/START23B/problems/MAXMINK
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 1, N = 41, S = 40 * 40 + 1, MIN = -1e7;

// dp[i][k][s]
int n, k, a[N], b[N];
int dp[N][N][S][S], cache[N][N][S];

int f(int i, int k, int s) {
	if(min(k, s) < 0) return 0;
	if(i == 0) return k == 0 && s == 0;
	int &ans = dp[i][k][s];
	if(cache[i][k][s]) return ans;
	cache[i][k][s] = 1;

	ans = max(ans, f(i - 1, k - 1, s - a[i]) + b[i]);
	ans = max(ans, f(i - 1, k, s1, s2));
	return ans;
}

void run_test(int testcase) {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			for(int s = 0; s < S; s++) {
				dp[i][j][s] = MIN;
				cache[i][j][s] = 0;
			}
		}
	}


	int ans = 0;
	for(int s1 = 0; s1 < S; s1++)
		for(int s2 = 0; s2 < S; s2++)
			if(f(n, k, s1, s2)) ans = max(ans, min(s1, s2));
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