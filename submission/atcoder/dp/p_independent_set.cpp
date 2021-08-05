#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 1e5 + 20, MOD = 1e9 + 7;

int n, v, u, dp[N][2];
vector <int> adj[N];

int add(int x, int y) {return (x + y) % MOD;}
int mul(int x, int y) {return 1ll * x * y % MOD;}

void dfs(int node, int parent) {
	dp[node][0] = dp[node][1] = 1;
	for(int &child: adj[node]) {
		if(child == parent) continue;
		dfs(child, node);
		dp[node][0] = mul(dp[node][0], add(dp[child][0], dp[child][1]));
		dp[node][1] = mul(dp[node][1], dp[child][0]);
	}
}

void run_test(int testcase) {
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	cout << add(dp[1][0], dp[1][1]);
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