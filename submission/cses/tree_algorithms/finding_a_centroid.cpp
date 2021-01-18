#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 20;

int n, u, v, dp[N];
vector <int> adj[N], centroids;

int dfs(int node, int parent) {
	dp[node] = 1;
	for(int child: adj[node]) {
		if(child != parent) {
			dp[node] += dfs(child, node);
		}
	}
	return dp[node];
}

void find_centroids(int node, int parent) {
	int max_size = 0;
	for(int child: adj[node]) {
		if(child == parent) continue;
		find_centroids(child, node);
		max_size = max(max_size, dp[child]);
	}

	max_size = max(max_size, n - dp[node]);
	if(max_size <= n / 2) {
		return centroids.push_back(node);;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	find_centroids(1, 0);
	cout << centroids[0];
}