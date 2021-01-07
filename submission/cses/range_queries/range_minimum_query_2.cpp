#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 20;

struct node {
	int val;
	node(int x = INT_MAX): val(x) {}
} tree[N << 2];

int n, q, a[N], t, l, r;

node merge(node &lch, node &rch) {
	node ans = node();
	ans.val = min(lch.val, rch.val);
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
		par.val = val;
	}
	else {
		int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
		if(start <= idx and idx <= mid) {
			update(lid, start, mid, idx, val);
		} else {
			update(rid, mid + 1, end, idx, val);
		}

		node &lch = tree[lid];
		node &rch = tree[rid];
		par.val = min(lch.val, rch.val);
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

	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);
	while(q--) {
		cin >> t >> l >> r;
		if(t == 1) update(1, 1, n, l, r);
		else cout << query(1, 1, n, l, r).val << "\n";
	}
}