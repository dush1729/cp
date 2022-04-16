class Solution {
public:
	int maximumScore(vector<int>& a, vector<vector<int>>& edges) {
		int n = a.size();
		set <pair <int, int>> adj[n];
		for(auto &v: edges) {
			adj[v[0]].insert({a[v[1]], v[1]});
			adj[v[1]].insert({a[v[0]], v[0]});
		}

		int ans = -1;
		for(auto &edge: edges) {
			int u = edge[0], v = edge[1];

			adj[u].erase({a[v], v});
			adj[v].erase({a[u], u});

			if(adj[u].size() > 0 && adj[v].size() > 0) {
				auto [umx, unode] = *--adj[u].end();
				adj[u].erase(--adj[u].end());
				auto [vmx, vnode] = *--adj[v].end();
				adj[v].erase(--adj[v].end());
				if(unode != vnode) {
					ans = max(ans, a[u] + a[v] + umx + vmx);
				} else {
					if(adj[u].size() > 0) {
						ans = max(ans, a[u] + a[v] + vmx + (--adj[u].end())->first);
					}
					if(adj[v].size() > 0) {
						ans = max(ans, a[u] + a[v] + umx + (--adj[v].end())->first);
					}
				}
				adj[u].insert({umx, unode});
				adj[v].insert({vmx, vnode});
			}

			adj[u].insert({a[v], v});
			adj[v].insert({a[u], u});
		}
		return ans;
	}
};