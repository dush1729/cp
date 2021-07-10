#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n, m, u, v;
	cin >> n >> m;
	vector <int> adj[n], dp(n);
	while(m--) {
		cin >> u >> v;
		adj[--v].push_back(--u);
	}

	function <int(int)> f = [&](int node) {
		int &ans = dp[node];
		if(ans) return ans;
		ans = 1;

		for(int parent: adj[node]) {
			ans = max(ans, f(parent) + 1);
		}
		return ans;
	};

	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, f(i));
	cout << ans - 1;
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