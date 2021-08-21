// https://cses.fi/problemset/task/1197/

const int MAX = 1e9;

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