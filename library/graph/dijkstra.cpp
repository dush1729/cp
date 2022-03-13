/*
Problems
https://codeforces.com/contest/20/problem/C
https://codeforces.com/contest/1076/problem/D
https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths
*/

struct DIJKSTRA {
	struct node {
		int city;
		ll cost;

		bool operator<(const node &rhs) const {
			return cost > rhs.cost;
		}
	};

	vector <ll> d;
	vector <int> vis, p;
	priority_queue <node> pq;

	void add(int node, int parent, ll dist) {
		pq.push({node, dist});
		d[node] = dist;
		p[node] = parent;
	}

	DIJKSTRA(const vector <vector <pair <int, int>>> &g, int source) {
		int n = g.size();
		d.resize(n, 1e18), vis.resize(n, 0), p.resize(n, -1);

		add(source, -1, 0);
		while(!pq.empty()) {
			auto [node, dist] = pq.top();
			pq.pop();
			if(vis[node]) continue;
			vis[node] = 1;

			for(const auto &[child, c]: g[node])
				if(d[child] > dist + c) add(child, node, dist + c);
		}
	}

	vector <int> get_path(int i) {
		if(!vis[i]) return {};

		vector <int> path;
		for( ; i != -1; i = p[i]) path.push_back(i);
		reverse(path.begin(), path.end());
		return path;
	}
};