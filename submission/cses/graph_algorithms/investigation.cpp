#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 1e5 + 2, MOD = 1e9 + 7;
const ll MAX = 1e18;

struct city {
	ll id, dist;
	bool operator <(const city &rhs) const {
		return dist > rhs.dist;
	}
};

int n, m, u, v, c;
vector <pair <int, int>> adj[N];
ll dist[N], ways[N], f[N], minf[N], maxf[N], vis[N];
priority_queue <city> pq;

void add(int node, ll d, ll w, int flights, ll min_flights, ll max_flights) {
	pq.push({node, d});
	dist[node] = d;
	ways[node] = w;
	f[node] = flights;
	minf[node] = min_flights;
	maxf[node] = max_flights;
}

void dijkstra() {
	add(1, 0, 1, 0, 0, 0);
	while(!pq.empty()) {
		auto [node, d] = pq.top();
		pq.pop();
		if(vis[node]) continue;
		vis[node] = 1;

		for(auto &[child, c]: adj[node]) {
			if(dist[child] > d + c) {
				add(child, d + c, ways[node], f[node] + 1, minf[node] + 1, maxf[node] + 1);
			} else if(dist[child] == d + c) {
				ways[child] = (ways[child] + ways[node]) % MOD;
				minf[child] = min(minf[child], minf[node] + 1);
				maxf[child] = max(maxf[child], maxf[node] + 1);
			}
		}
	}
}

void run_test(int testcase) {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
	}

	for(int i = 1; i <= n; i++) dist[i] = MAX;
	dijkstra();
	cout << dist[n] << " " << ways[n] << " " << minf[n] << " " << maxf[n];
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