#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 2e5 + 20;

int n, a[N], u, v, ans[N];
vector <int> adj[N];
set <int> s[N];

void go(int node, int parent) {
	s[node].insert(a[node]);
	for(int child: adj[node]) {
		if(child == parent) continue;

		go(child, node);
		if(s[node].size() < s[child].size()) swap(s[node], s[child]);
		for(int &x: s[child]) s[node].insert(x);
	}
	ans[node] = s[node].size();
}

void run_test(int testcase) {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	go(1, 0);
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
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