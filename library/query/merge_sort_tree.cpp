/*
Problems
https://www.spoj.com/problems/KQUERY/
*/

#include "bits/stdc++.h"
using namespace std;

const int N = 3e4 + 20;

int n, a[N], q, l, r, k;
struct node {
	vector <int> v;
} tree[N << 2];

void merge(vector <int> &v, vector <int> &a, vector <int> &b) {
	for(int i = 0, j = 0; v.size() < a.size() + b.size(); ) {
		if(i < a.size() and j < b.size()) {
			if(a[i] < b[j]) v.push_back(a[i++]);
			else v.push_back(b[j++]);
		} else if(i < a.size()) v.push_back(a[i++]);
		else v.push_back(b[j++]);
	}
}

void build(int id, int start, int end) {
	auto &par = tree[id];
	if(start == end) {
		par.v.push_back(a[start]);
		return ;
	}
	
	int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
	build(lid, start, mid);
	build(rid, mid + 1, end);
	merge(par.v, tree[lid].v, tree[rid].v);
}

int query(int id,int start,int end) {
	if(l > end or r < start) return 0;
	auto &par = tree[id];
	if(start >= l and end <= r) {
		return par.v.end() - upper_bound(par.v.begin(), par.v.end(), k);
	}
	
	int mid = (start + end) >> 1, lid = id << 1, rid = lid + 1;
	int ans1 = query(lid, start, mid);
	int ans2 = query(rid, mid + 1, end);
	return ans1 + ans2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	build(1, 1, n);
	cin >> q;
	while(q--) {
		cin >> l >> r >> k;
		cout << query(1, 1, n) << "\n";
	}
}