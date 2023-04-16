//https://cses.fi/problemset/task/1688/
//https://leetcode.com/contest/weekly-contest-341/problems/minimize-the-total-price-of-the-trips/

struct LCA {
	int n, l;
	vector <vector <int>> g, p;
	vector <int> d;
	LCA(vector <vector <int>> &gr, int root): n(gr.size()), l(log2(n) + 1), g(gr), p(n, vector (l, -1)), d(n) {
		dfs(root, -1, 0);
		for(int j = 1; j < l; j++)
			for(int i = 0; i < n; i++) // 0 indexed
				if(p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
	}

	void dfs(int node, int parent, int depth) {
		d[node] = depth;
		if(parent != -1) p[node][0] = parent;
		for(const int &child: g[node])
			if(child != parent) dfs(child, node, depth + 1);
	}

	int lca(int u, int v) {
		if(u == v) return u;
		if(d[u] < d[v]) swap(u, v);
		for(int j = log2(d[u]); j >= 0; j--)
			if(d[u] - (1 << j) >= d[v]) u = p[u][j];
		if(u == v) return u;
		for(int j = log2(d[u]); j >= 0; j--)
			if(p[u][j] != p[v][j]) u = p[u][j], v = p[v][j];
		return p[u][0];
	}
};