#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

struct BIT {
	int n;
	vector <ll> tree;
	BIT(int SZ): tree(SZ + 1) {
		n = SZ;
	}

	void update(int x, ll delta) {
		for(; x <= n; x += x & -x) tree[x] = max(tree[x], delta);
	}

	ll query(int x) {
		ll res = 0;
		for(; x > 0; x -= x & -x) res = max(res, tree[x]);
		return res;
	}
};

void run_test(int testcase) {
	int n;
	cin >> n;
	vector h(n, 0), a(n, 0);
	for(int &x: h) cin >> x;
	for(int &x: a) cin >> x;

	auto bit = BIT(n);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ll res = bit.query(h[i] - 1) + a[i];
		bit.update(h[i], res);
		ans = max(ans, res);
	}
	cout << ans;
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