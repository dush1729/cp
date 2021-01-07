#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20, MOD = 1e9 + 7;

int n, m, u, v, vis[N], dp[N];
vector <int> adj[N];
stack <int> s;

void dfs(int node, int parent) {
	vis[node] = 1;
	for(int child: adj[node])
		if(!vis[child]) dfs(child, node);
	s.push(node);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	dfs(1, 0);

	dp[1] = 1;
	while(!s.empty()) {
		int node = s.top();
		s.pop();

		for(int child: adj[node]) {
			dp[child] = (dp[child] + dp[node]) % MOD;
		}
	}

	cout << dp[n];
}