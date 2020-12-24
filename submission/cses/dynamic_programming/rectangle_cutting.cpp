#include "bits/stdc++.h"
using namespace std;

const int N = 5e2 + 20;

int x, y, dp[N][N];

int f(int x, int y) {
	if(dp[x][y] or x == y) return dp[x][y];

	int &ans = dp[x][y];
	ans = INT_MAX;
	for(int l = 1; l < x; l++) {
		ans = min(ans, f(l, y) + f(x - l, y) + 1);
	}
	for(int l = 1; l < y; l++) {
		ans = min(ans, f(x, l) + f(x, y - l) + 1);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> y;
	cout << f(x, y);
}