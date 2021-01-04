/*
Problems
https://cses.fi/problemset/task/1672
https://www.facebook.com/codingcompetitions/hacker-cup/2019/round-1/problems/A
*/

#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 512;
const ll MAX = 1e18;

int n, m, q, u, v, c;
ll dp[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(j != i) {
				dp[i][j] = MAX;
			}
		}
	}

	while(m--) {
		cin >> u >> v >> c;
		dp[u][v] = min(dp[u][v], 1ll * c);
		dp[v][u] = min(dp[v][u], 1ll * c);
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	while(q--) {
		cin >> u >> v;
		ll ans = dp[u][v];
		if(ans == MAX) ans = -1;
		cout << ans << "\n";
	}
}