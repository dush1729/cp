#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

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

	int dist(int u, int v) {
		return d[u] + d[v] - d[lca(u, v)] * 2;
	}
};

void run_test(int testcase) {
	int n, q, u, v;
	cin >> n >> q;
	vector <vector <int>> g(n + 1);
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto ds = LCA(g, 1);
	while(q--) {
		cin >> u >> v;
		cout << ds.dist(u, v) << "\n";
	}
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