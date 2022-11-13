/*
Problems
https://codeforces.com/contest/1354/problem/D
https://binarysearch.com/problems/Bubble-Swap
*/

struct BIT {
	int n;
	vector <ll> tree;
	BIT(int SZ): n(SZ), tree(SZ + 1)  {}

	// a[x] += delta
	void update(int x, ll delta) {
		assert(x > 0);
		for(; x <= n; x += x & -x) tree[x] += delta;
	}

	// sum from a[1] to a[x]
	ll query(ll x) {
		ll sum = 0;
		for(; x > 0; x -= x & -x) sum += tree[x];
		return sum;
	}
};