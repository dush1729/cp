#include "bits/stdc++.h"
using namespace std;
#define ll long long 

const int N = 2e5 + 20;

int n, q, x, a, b;
ll dp[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		dp[i] = dp[i - 1] + x;
	}

	while(q--) {
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << "\n";
	}
}