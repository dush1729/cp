#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

int n, m, u, v, vis[N], dp[N], p[N];
vector <int> adj[N], ans;
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
			if(dp[child] < dp[node] + 1) {
				dp[child] = dp[node] + 1;
				p[child] = node;
			}
		}
	}

	if(!vis[n]) cout << "IMPOSSIBLE";
	else {
		while(n != 1) {
			ans.push_back(n);
			n = p[n];
		}
		ans.push_back(n);

		reverse(ans.begin(), ans.end());

		cout << ans.size() << "\n";
		for(int i: ans) cout << i << " ";
	}
}