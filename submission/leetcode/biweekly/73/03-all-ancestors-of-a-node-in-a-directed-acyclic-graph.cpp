struct TOPOLOGICAL_SORT {
	// leaf -> root
	vector <vector <int>> adj;
	vector <int> vis, order;
	int cycle = 0;

	void dfs(int node) {
		vis[node] = 1;
		for(int child: adj[node])
			if(!vis[child]) dfs(child);
			else if(vis[child] == 1) cycle = 1;
		vis[node] = 2;
		order.push_back(node);
	}

	TOPOLOGICAL_SORT(const vector <vector <int>> &g) : adj(g) {
		int n = g.size();
		vis.resize(n);

		for(int i = 0; i < n; i++)
			if(!vis[i]) dfs(i);

		// uncomment for root -> leaf
		reverse(order.begin(), order.end());
	}
};

class Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector adj(n, vector (0, 0)), ans(n, vector (0, 0));
		for(auto &v: edges) adj[v[0]].push_back(v[1]);

		auto ts = TOPOLOGICAL_SORT(adj);
		set <int> s[n];
		for(int &node: ts.order) {
			for(const int &child: adj[node]) {
				s[child].insert(node);
				for(int x: s[node]) {
					s[child].insert(x);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			ans[i] = vector <int> (s[i].begin(), s[i].end());
        }
		return ans;
	}
};