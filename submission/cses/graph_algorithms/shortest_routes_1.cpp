#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 1e5 + 20;
const ll MAX = 1e18;

int n, m, u, v, c;
ll dp[N];
vector <pair <int, int>> adj[N];
priority_queue <pair <ll, int>> pq;
bool processed[N];

void add(int node, ll dist) {
	dp[node] = dist;
	pq.push({-dist, node});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m--) {
		cin >> u >> v >> c;
		adj[u].push_back({c, v});
	}

	for(int i = 1; i <= n; i++) dp[i] = MAX;

	add(1, 0);
	while(!pq.empty()) {
		int node=pq.top().second;
		pq.pop();
		if(processed[node]) continue;

		processed[node] = true;
		for(auto &[cost, child]: adj[node]) {
			if(dp[child] <= dp[node] + cost) continue;
			add(child, dp[node] + cost);
		}
	}

	for(int i = 1; i <= n; i++) cout << dp[i] << " ";
}