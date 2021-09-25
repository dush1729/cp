#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

const int N = 2e5 + 20;

int n, m, a[N], k, x;

struct node {
	ll pre, suf, sum, maxSum;
	node(ll x = 0): pre(x), suf(x), sum(x), maxSum(x) {}
} tree[N << 2];

node merge(node &lch, node &rch) {
	node ans = node();
	ans.pre = max(lch.pre, lch.sum + rch.pre);
	ans.suf = max(rch.suf, rch.sum + lch.suf);
	ans.sum = lch.sum + rch.sum;
	ans.maxSum = max({lch.maxSum, rch.maxSum, lch.suf + rch.pre});
	return ans;
}

void build(int id, int start, int end) {
	node &par = tree[id];
	if(start == end) par = node(a[start]);
	else {
		int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
		build(lid, start, mid);
		build(rid, mid + 1, end);

		node &lch = tree[lid];
		node &rch = tree[rid];
		par = merge(lch, rch);
	}
}

void update(int id, int start, int end, int idx, int val) {
	node &par = tree[id];
	if(start == end) {
		par = node(val);
		a[start] = val;
	} else {
		int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
		if(start <= idx and idx <= mid) {
			update(lid, start, mid, idx, val);
		} else {
			update(rid, mid + 1, end, idx, val);
		}

		node &lch = tree[lid];
		node &rch = tree[rid];
		par = merge(lch, rch);
	}
}

node query(int id, int start, int end, int l, int r) {
	if(r < start or end < l) return node();
	node &par = tree[id];
	if(l <= start and end <= r) return par;

	int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
	node p1 = query(lid, start, mid, l, r);
	node p2 = query(rid, mid + 1, end, l, r);
	return merge(p1, p2);
}

void run_test(int testcase) {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);
	while(m--) {
		cin >> k >> x;
		update(1, 1, n, k, x);
		cout << max(0ll, query(1, 1, n, 1, n).maxSum) << "\n";
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