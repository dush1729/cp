#include "bits/stdc++.h"
using namespace std;

struct DSU {
	int count, maxsize;
	struct node {
		int parent, size;
		node(int id = 0): parent(id), size(1) {}
	};

	vector <node> data;

	DSU(int SZ = 0): count(SZ), maxsize(1), data(SZ + 1) {
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
		maxsize = max(maxsize, data[a].size);

		return true;
	}
};

int n, m, u, v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	auto dsu = DSU(n);
	while(m--) {
		cin >> u >> v;
		dsu.join(u, v);
		cout << dsu.count << " " << dsu.maxsize << "\n";
	}
}