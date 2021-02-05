#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 2e5 + 20;

int n, u, v;
vector <int> adj[N];
ll sub[N], dp[N];

ll dfs(int node, int parent) {
	sub[node] = 1;
	for(int child: adj[node]) {
		if(child == parent) continue;
		dfs(child, node);
		sub[node] += sub[child];
		dp[node] += dp[child] + sub[child];
	}
	return dp[node];
}

void go(int node, int parent, ll ans) {
	dp[node] = ans;
	for(int child: adj[node]) {
		if(child == parent) continue;
		go(child, node, ans + n - 2 * sub[child]);
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

	dp[1] = dfs(1, 0);
	go(1, 0, dp[1]);
	for(int i = 1; i <= n; i++) cout << dp[i] << " ";
}