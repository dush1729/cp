/*
Problems
https://cses.fi/problemset/task/1681
https://codeforces.com/contest/919/problem/D
*/

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
		//reverse(order.begin(), order.end());
	}
};