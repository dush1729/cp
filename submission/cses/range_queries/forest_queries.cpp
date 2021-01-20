#include "bits/stdc++.h"
using namespace std;
#define y1 xoxo

const int N = 1e3 + 20;

int n, q, dp[N][N], x1, y1, x2 ,y2;
string a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a;

		for(int j = 0; j < n; j++) {
			dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j]
					- dp[i][j] + (a[j] == '*');
		}
	}

	while(q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
	}
}