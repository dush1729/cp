/*
Problems
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial
https://www.spoj.com/problems/MST
https://cses.fi/problemset/task/1675
*/

struct KRUSKAL {
	DSU dsu;
	priority_queue <pair<int, pair<int, int>>> pq;

	KRUSKAL(int SZ) {
		dsu = DSU(SZ);
	}

	void add_edge(int u, int v, int c) {
		pq.push({-c, {u, v}});
	}

	long long cost() {
		long long ans = 0;
		while(not pq.empty()) {
			auto p = pq.top();
			int c = -p.first;
			int u = p.second.first, v = p.second.second;
			pq.pop();

			if(dsu.join(u,v)) ans += c;
		}
		return ans;
	}
};