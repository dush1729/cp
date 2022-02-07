#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0;

struct BIT {
	int n;
	vector <int> tree;
	BIT(int SZ): tree(SZ + 1) {
		n = SZ;
	}

	// a[x] += delta
	void update(int x, int delta) {
		for(; x <= n; x += x & -x) tree[x] += delta;
	}

	// sum from a[1] to a[x]
	int query(int x) {
		int sum = 0;
		for(; x > 0; x -= x & -x) sum += tree[x];
		return sum;
	}
};

struct query {
	int l, r, i;
};

void run_test(int testcase) {
	int n;
	cin >> n;
	vector <query> a(n);
	vector <int> ans1(n), ans2(n), compress;
	for(int i = 0; i < n; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].i = i;
		compress.push_back(a[i].l);
		compress.push_back(a[i].r);
	}
	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());

	int m = compress.size();
	vector <vector <pair <int, int>>> ql(m + 1), qr(m + 1);
	for(auto &[l, r, i]: a) {
		int nl = lower_bound(compress.begin(), compress.end(), l) - compress.begin() + 1;
		int nr = lower_bound(compress.begin(), compress.end(), r) - compress.begin() + 1;
		l = nl, r = nr;
		ql[l].push_back({r, i});
		qr[r].push_back({l, i});
	}

	auto bitl = BIT(m), bitr = BIT(m);
	for(int r = 1; r <= m; r++) {
		for(auto &[l, i]: qr[r]) {
			bitr.update(l, +1);
		}
		for(auto &[l, i]: qr[r]) {
			ans1[i] = bitr.query(r) - bitr.query(l - 1) - 1;
		}
	}

	for(int l = 1, segments = 0; l <= m; l++) {
		for(auto &[r, i]: ql[l]) {
			bitl.update(r, +1);
			segments++;
		}
		for(auto &[r, i]: ql[l]) {
			ans2[i] = segments - bitl.query(r - 1) - 1;
		}
	}

	for(int &x: ans1) cout << x << " ";cout << "\n";
	for(int &x: ans2) cout << x << " ";cout << "\n";
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