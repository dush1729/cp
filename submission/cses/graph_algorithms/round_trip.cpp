#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

int n, m, u, v, c[N], p[N];
vector <int> adj[N];

void dfs(int node, int parent) {
	c[node] = 1, p[node] = parent;
	for(int child : adj[node]) {
		if(child == parent) continue;

		if(c[child] == 0) dfs(child, node);
		else if(c[child] == 1) {
			vector <int> ans = {child};
			while(node != child) {
				ans.push_back(node);
				node = p[node];
			}
			ans.push_back(child);

			cout << ans.size() << "\n";
			for(int node : ans) cout << node << " ";

			exit(0);
		}
	}
	c[node] = 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; i++) {
		if(c[i]) continue;
		dfs(i, 0);
	}

	cout << "IMPOSSIBLE";
}