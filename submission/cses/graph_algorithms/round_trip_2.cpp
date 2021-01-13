#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

int n, m, u, v, vis[N];
vector <int> adj[N], vec, ans;

void go(int node) {
	vec.push_back(node);
	vis[node] = 1;
	for(int child: adj[node]) {
		if(!vis[child]) go(child);
		else if(vis[child] == 1) {
			ans.push_back(child);
			while(vec.back() != child) {
				ans.push_back(vec.back());
				vec.pop_back();
			}
			ans.push_back(child);

			reverse(ans.begin(), ans.end());
			cout << ans.size() << "\n";
			for(int node: ans) cout << node << " ";

			exit(0);
		}
	}
	vec.pop_back();
	vis[node] = 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		assert(u != v);
		adj[u].push_back(v);
	}

	for(int i = 1; i <= n; i++) {
		if(!vis[i]) go(i);
	}
	cout << "IMPOSSIBLE";
}