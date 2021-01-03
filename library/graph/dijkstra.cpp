/*
Problems
https://codeforces.com/contest/20/problem/C
https://codeforces.com/contest/1076/problem/D
*/

#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 1e5 + 20;
const ll MAX = 1e18;

int n, m, u, v, c, p[N];
long long dp[N];
vector <pair <int, int>> adj[N];
priority_queue <pair <ll, int>> pq;
vector <int> ans;
bool processed[N];

void add(int node, int parent, ll dist) {
	dp[node] = dist;
	pq.push({-dist ,node});
	p[node] = parent;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m--) {
		cin >> u >> v >> c;
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}

	for(int i = 1; i <= n; i++) dp[i] = MAX;

	add(1, 0, 0);
	while(!pq.empty()) {
		int node=pq.top().second;
		pq.pop();
		if(processed[node]) continue;
		processed[node] = true;

		for(auto &p: adj[node]) {
			int cost = p.first, child = p.second;
			if(dp[child] <= dp[node] + cost) continue;
			add(child, node, dp[node] + cost);
		}
	}

	if(p[n] == 0) cout << -1;
	else {
		for(int i = n; i != 0; i = p[i]) ans.push_back(i);
		reverse(ans.begin(), ans.end());
		for(auto i: ans) cout << i << " ";
	}
}