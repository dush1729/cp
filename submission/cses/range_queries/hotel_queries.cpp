#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 20;

int n, m, a[N], x;

struct node {
	int idx;
	node(int x = 0): idx(x) {}
} tree[N << 2];

node merge(node &lch, node &rch) {
	node ans = node();
	if(a[lch.idx] > a[rch.idx]) ans.idx = lch.idx;
	else ans.idx = rch.idx;
	return ans;
}

void build(int id, int start, int end) {
	node &par = tree[id];
	if(start == end) par = node(start);
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
		a[start] -= val;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);

	while(m--) {
		cin >> x;

		int lo = 1, hi = n, idx = 0;
		while(lo <= hi) {
			int mid = (lo + hi) >> 1;
			auto node = query(1, 1, n, 1, mid);

			if(a[node.idx] >= x) hi = mid - 1, idx = node.idx;
			else lo = mid + 1;
		}

		if(a[idx] <= 0) cout << "0 ";
		else {
			cout << idx << " ";
			update(1, 1, n, idx, x);
		}
	}
}