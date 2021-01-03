/*
Problems
https://www.spoj.com/problems/HORRIBLE
https://codeforces.com/contest/145/problem/E
*/

#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

struct node {
	int val, lazy;
	node(): val(0), lazy(0) {}
} tree[N << 2];

node merge(node &lch, node &rch) {
	node ans = node();
	ans.val = lch.val + rch.val;
	return ans;
}

void push(node &par, node &lch, node &rch, int start, int end, int val) {
	par.val += (end - start + 1) * val;
	if(start != end) {
		lch.lazy += val;
		rch.lazy += val;
	}
	par.lazy = 0;
}

void build(int id, int start, int end) {
	node &par = tree[id];
	if(start == end) par = node();
	else {
		int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
		build(lid, start, mid);
		build(rid, mid + 1, end);

		node &lch = tree[lid];
		node &rch = tree[rid];
		par = merge(lch, rch);
	}
}

void point_update(int id, int start, int end, int idx, int val) {
	node &par = tree[id];
	if(start == end) {
		par.val += val;
	}
	else {
		int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
		if(start <= idx and idx <= mid) {
			point_update(lid, start, mid, idx, val);
		} else {
			point_update(rid, mid + 1, end, idx, val);
		}

		node &lch = tree[lid];
		node &rch = tree[rid];
		par.val = lch.val + rch.val;
	}
}

node no_lazy_query(int id, int start, int end, int l, int r) {
	if(r < start or end < l) return node();
	node &par = tree[id];
	if(l <= start and end <= r) return par;

	int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
	node p1 = no_lazy_query(lid, start, mid, l, r);
	node p2 = no_lazy_query(rid, mid + 1, end, l, r);
	return merge(p1, p2);
}

// Warning! Time Complexity O(nlogn)!
void no_lazy_update(int id, int start, int end, int l, int r, int val) {
	if(start > end or start > r or end < l) return ;
	node &par = tree[id];
	if(start == end) {
		par.val += val;
		return;
	}

	int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
	no_lazy_update(lid, start, mid, l, r, val);
	no_lazy_update(rid, mid + 1, end, l, r, val);
	node &lch = tree[lid];
	node &rch = tree[rid];
	par = merge(lch, rch);
}

void update(int id, int start, int end, int l, int r, int val) {
	int lid = id << 1, rid = lid + 1;
	node &par = tree[id], &lch = tree[lid], &rch = tree[rid];
	if(par.lazy) {
		push(par, lch, rch, start, end, par.lazy);
	}

	if(start > end or start > r or end < l) return ;

	if(start >= l and end <= r) {
		push(par, lch, rch, start, end, val);
		return ;
	}

	int mid = (start + end) >> 1;
	update(lid, start, mid, l, r, val);
	update(rid, mid + 1, end, l, r, val);
	par = merge(lch, rch);
}

node query(int id, int start, int end, int l, int r) {
	if(start > end or start > r or end < l) return node();
	int lid = id << 1, rid = lid + 1;
	node &par = tree[id], &lch = tree[lid], &rch = tree[rid];
	if(par.lazy) {
		push(par, lch, rch, start, end, par.lazy);
	}

	if(start >= l and end <= r) return par;

	int mid = (start + end) >> 1;
	node p1 = query(lid, start, mid, l, r);
	node p2 = query(rid, mid + 1, end, l, r);
	return merge(p1, p2);
}

int main() {
}