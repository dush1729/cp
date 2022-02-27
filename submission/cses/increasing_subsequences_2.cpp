#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, MOD = 1e9 + 7;

int compress(vector <int> &v) {
	if(v.empty()) return 0;
	vector <int> s = v;
	sort(s.begin(), s.end());
	s.resize(unique(s.begin(), s.end()) - s.begin());

	int mx = 1;
	for(int &x: v) {
		x = lower_bound(s.begin(), s.end(), x) - s.begin() + 2;
		mx = max(mx, x);
	}
	return mx;
}

void add(int &x, int y) {x = (x + y) % MOD;}

struct BIT {
	int n;
	vector <int> tree;
	BIT(int SZ): tree(SZ + 1), n(SZ) {}

	void update(int x, int delta) {
		for(; x <= n; x += x & -x) add(tree[x], delta);
	}

	int query(int x) {
		int sum = 0;
		for(; x > 0; x -= x & -x) add(sum, tree[x]);
		return sum;
	}
};

void run_test(int testcase) {
	int n, ans = 0;
	cin >> n;
	vector a(n, 0);
	for(int &x: a) cin >> x;

	n = compress(a);
	auto bit = BIT(n);
	bit.update(1, 1);
	for(const int &x: a) {
		int q = bit.query(x - 1);
		bit.update(x, q);
	}

	cout << (bit.query(n) - 1 + MOD) % MOD;
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