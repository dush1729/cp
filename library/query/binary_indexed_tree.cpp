/*
Problems
https://codeforces.com/contest/1354/problem/D
https://binarysearch.com/problems/Bubble-Swap
*/

struct BIT {
	int n;
	vector <int> tree;
	BIT(int SZ): tree(SZ + 1), n(SZ) {}

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