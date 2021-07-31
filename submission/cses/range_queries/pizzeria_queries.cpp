#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 2e5 + 20;

int a[N], l[N], r[N];

struct node {
	int pre, suf;
	node(int x = INT_MAX, int y = INT_MAX): pre(x), suf(y) {}
} tree[N << 2];

node merge(node &lch, node &rch) {
	node ans = node();
	ans.pre = min(lch.pre, rch.pre);
	ans.suf = min(lch.suf, rch.suf);
	return ans;
}

void build(int id, int start, int end) {
	node &par = tree[id];
	if(start == end) {
		par = node(l[start], r[start]);
	} else {
		int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
		build(lid, start, mid);
		build(rid, mid + 1, end);
		par = merge(tree[lid], tree[rid]);
	}
}

void update(int id, int start, int end, int idx, int pre, int suf) {
	node &par = tree[id];
	if(start == end) {
		l[start] = pre, r[start] = suf;
		par = node(l[start], r[start]);
	} else {
		int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
		if(start <= idx and idx <= mid) {
			update(lid, start, mid, idx, pre, suf);
		} else {
			update(rid, mid + 1, end, idx, pre, suf);
		}
		par = merge(tree[lid], tree[rid]);
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
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		l[i] = a[i] - i;
		r[i] = a[i] + i;
	}
	build(1, 1, n);

	int t, k, x;
	while(q--) {
		cin >> t;
		if(t == 1) {
			cin >> k >> x;
			a[k] = x;
			update(1, 1, n, k, a[k] - k, a[k] + k);
		} else {
			cin >> k;
			cout << min(query(1, 1, n, 1, k).pre + k, query(1, 1, n, k, n).suf - k) << "\n";
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