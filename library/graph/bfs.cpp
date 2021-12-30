struct BFS {
	queue <int> q;
	vector <int> d, p;

	void add(int node, int parent, int dist) {
		q.push(node);
		d[node] = dist;
		p[node] = parent;
	}

	BFS(const vector <vector <int>> &g, const vector <int> &sources) {
		int n = g.size();
		d.assign(n, -1);
		p.assign(n, -1);

		for(const int &node: sources) add(node, -1, 0);
		while(!q.empty()) {
			const int node = q.front();
			q.pop();
			for(const int &child: g[node]) {
				if(d[child] == -1) add(child, node, d[node] + 1);
			}
		}
	}
};