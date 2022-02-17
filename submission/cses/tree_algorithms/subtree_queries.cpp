#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0;

struct BIT {
	int n;
	vector <ll> tree;
	BIT(int SZ): n(SZ), tree(SZ + 1) {}

	void update(int x, int delta) {
		for(; x <= n; x += x & -x) tree[x] += delta;
	}

	ll query(int x) {
		ll sum = 0;
		for(; x > 0; x -= x & -x) sum += tree[x];
		return sum;
	}
};

void run_test(int testcase) {
	int n, q, type, s, x;
	cin >> n >> q;
	vector a(n + 1, 0), val(n + 1, 0), st(n + 1, 0), ed(n + 1, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector <vector <int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int time = 0;
	auto bit = BIT(n);
	function <void(int, int)> euler = [&](int node, int parent) {
		st[node] = ++time;
		val[time] = a[node];
		bit.update(time, a[node]);
		for(const int &child: adj[node])
			if(child != parent) euler(child, node);
		ed[node] = time;
	};

	euler(1, 0);
	while(q--) {
		cin >> type >> s;
		if(type == 1) {
			cin >> x;
			s = st[s];
			bit.update(s, x - val[s]);
			val[s] = x;
		} else {
			cout << bit.query(ed[s]) - bit.query(st[s] - 1) << "\n";
		}
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