#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, MAX = 1e9;

struct edge {
	int u, v, c;
};

struct BELLMAN_FORD {
	vector <ll> dp;
	vector <int> p;
	vector <edge> edges;
	int negative_cycle = 0;
	vector <int> cycle;

	BELLMAN_FORD(int n, int source, vector <edge> &v) : edges(v), dp(n + 1, MAX), p(n + 1) {
		dp[source] = 0;
		for(int it = 0; it < n - 1; it++) relax();

		auto ndp = dp;
		relax();

		int node = 1;
		while(node <= n && ndp[node] == dp[node]) node++;

		if(node == n + 1) {
			negative_cycle = 0;
		} else {
			negative_cycle = 1;

			vector <int> vis(n + 1);
			for( ; !vis[node]; node = p[node]) {
				cycle.push_back(node);
				vis[node] = 1;
			}
			cycle.push_back(node);
			reverse(cycle.begin(), cycle.end());
		}
	}

	void relax() {
		for(auto &[u, v, c]: edges) {
			if(dp[v] > dp[u] + c) {
				dp[v] = dp[u] + c;
				p[v] = u;
			}
		}
	}
};

void run_test(int testcase) {
	int n, m, u, v, c;
	cin >> n >> m;
	vector <edge> edges;
	while(m--) {
		cin >> u >> v >> c;
		edges.push_back({u, v, c});
	}

	auto bf = BELLMAN_FORD(n, 1, edges);
	if(bf.negative_cycle) {
		cout << "YES\n";
		for(int &node: bf.cycle) cout << node << " ";
	} else {
		cout << "NO";
	}
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