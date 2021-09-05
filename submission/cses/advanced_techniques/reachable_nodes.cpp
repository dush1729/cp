#include "bits/stdc++.h"
#pragma GCC target("popcnt")
using namespace std;
#define ll long long
const int areTests = 0, N = 5e4;

bitset <N> a[N];
int vis[N];
vector <int> adj[N], order;

void dfs(int node) {
	vis[node] = 1;
	for(int &child: adj[node]) {
		if(!vis[child]) dfs(child);
	}
	order.push_back(node);
}

void run_test(int testcase) {
	int n, m, u, v;
	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		adj[--u].push_back(--v);
	}

	for(int i = 0; i < n; i++) {
		if(!vis[i]) dfs(i);
	}

	for(int &node: order) {
		a[node][node] = 1;
		for(int &child: adj[node]) {
			a[node] |= a[child];
		}
	}

	for(int i = 0; i < n; i++) {
		cout << a[i].count() << " ";
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