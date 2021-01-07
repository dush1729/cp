#include "bits/stdc++.h"
using namespace std;

struct DSU {
	int count;
	struct node {
		int parent, size;
		node(int id = 0): parent(id), size(1) {}
	};

	vector <node> data;

	DSU(int SZ = 0): count(SZ), data(SZ + 1) {
		iota(data.begin(), data.end(), 0);
	}

	int root(int i) {
		if(i != data[i].parent) {
			data[i].parent = root(data[i].parent);
		}
		return data[i].parent;
	}

	bool is_root(int i) {
		return i == root(i);
	}

	bool cycle(int a, int b) {
		return root(a) == root(b);
	}

	int set_size(int a) {
		return data[root(a)].size;
	}

	bool join(int a, int b) {
		a = root(a), b = root(b);
		if(a == b) return false;

		count--;
		if(data[a].size < data[b].size) swap(a, b);
		data[b].parent = a;
		data[a].size += data[b].size;

		return true;
	}
};

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

int n, m, a, b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	auto kruskal = KRUSKAL(n);
	while(m--) {
		cin >> a >> b >> c;
		kruskal.add_edge(a, b, c);
	}

	auto ans = kruskal.cost();
	if(kruskal.dsu.count > 1) cout << "IMPOSSIBLE";
	else cout << ans;
}