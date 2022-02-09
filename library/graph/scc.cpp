/*
Problems
https://codeforces.com/contest/427/problem/C
https://codeforces.com/contest/999/problem/E
*/

struct SCC {
	int col = 0;
	vector <vector <int>> adj, rev;
	vector <int> vis, order, c;

	void dfs(int node) {
		vis[node] = 1;
		for(const int &child: adj[node])
			if(!vis[child]) dfs(child);
		order.push_back(node);
	}

	void dfs_rev(int node) {
		c[node] = col;
		for(const int &child: rev[node])
			if(c[child] == -1) dfs_rev(child);
	}

	SCC(const vector <vector <int>> &g) : adj(g) {
		int n = g.size();
		rev.resize(n), vis.resize(n), c.resize(n, -1);

		for(int u = 0; u < n; u++)
			for(const int &v: adj[u]) rev[v].push_back(u);

		for(int i = 0; i < n; i++)
			if(!vis[i]) dfs(i);
		reverse(order.begin(), order.end());
		for(const int &node: order)
			if(c[node] == -1) dfs_rev(node), col++;
	}
};