#include "bits/stdc++.h"
using namespace std;

const int N = 1e2 + 20;

int t, n, m, dp[N][N];
string a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> m;

		for(int i = 1; i <= n; i++) {
			cin >> a;
			a = "$" + a;

			for(int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
				if(a[j] == 'B') dp[i][j]++;
				else if(a[j] == 'T') dp[i][j]--;
			}
		}

		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				for(int s = 1; i + s - 1 <= n and j + s - 1 <= m; s++) {
					int v = dp[i + s - 1][j + s - 1] - dp[i - 1][j + s - 1] - dp[i + s - 1][j - 1]
							+ dp[i - 1][j - 1];
					ans = max(ans, v);
				}
			}
		}

		cout << "Case " << tc << ": " << ans << "\n";
	}
}