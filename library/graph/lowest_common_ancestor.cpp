//https://cses.fi/problemset/task/1688/

struct LCA {
	int n, l;
	vector <vector <int>> g, p;
	vector <int> d;
	LCA(vector <vector <int>> &gr, int root): n(gr.size() - 1), l(log2(n) + 1), g(gr), p(n + 1, vector (l, -1)), d(n + 1) {
		dfs(root, 0, 0);
		for(int j = 1; j < l; j++)
			for(int i = 1; i <= n; i++)
				if(p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
	}

	void dfs(int node, int parent, int depth) {
		d[node] = depth;
		if(parent) p[node][0] = parent;
		for(int &child: g[node])
			if(child != parent) dfs(child, node, depth + 1);
	}

	int lca(int u, int v) {
		if(d[u] < d[v]) swap(u, v);
		for(int j = log2(d[u]); j >= 0; j--)
			if(d[u] - (1 << j) >= d[v]) u = p[u][j];
		if(u == v) return u;
		for(int j = log2(d[u]); j >= 0; j--)
			if(p[u][j] != p[v][j]) u = p[u][j], v = p[v][j];
		return p[u][0];
	}
};