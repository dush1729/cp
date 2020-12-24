#include "bits/stdc++.h"
using namespace std;

string a, b;

int solve(string &a, string &b) {
	int n = a.size(), m = b.size();
	vector <vector <int>> dp(2, vector <int> (m + 1, 0));
	iota(dp[0].begin(), dp[0].end(), 0);

	for(int i = 1; i <= n; i++) {
		int curr = i % 2, pv = 1 - curr;
		dp[curr][0] = i;

		for(int j = 1; j <= m; j++) {
			if(a[i - 1] == b[j - 1]) {
				dp[curr][j] = dp[pv][j - 1];
			} else {
				dp[curr][j] = min({dp[pv][j], dp[curr][j - 1], dp[pv][j - 1]}) + 1;
			}
		}
	}

	return dp[n % 2][m];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	cout << solve(a, b);
}