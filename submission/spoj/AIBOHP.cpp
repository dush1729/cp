#include "bits/stdc++.h"
using namespace std;

const int N = 7e3 + 20;

int t, dp[N][N];
string a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> a;

		int n = a.size();
		for(int l = n - 1; l >= 0; l--) {
			for(int r = l; r < n; r++) {
				if(r - l == 0) dp[l][r] = 1;
				else if(r - l == 1) dp[l][r] = max(1, 2 * (a[l] == a[r]));
				else if(a[l] == a[r]) dp[l][r] = 2 + dp[l + 1][r - 1];
				else dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
			}
		}

		cout << n - dp[0][n - 1] << "\n";
	}
}