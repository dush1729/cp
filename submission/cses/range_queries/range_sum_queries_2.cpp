#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 2e5 + 20;

int n, q, a[N], t, l, r;
ll tree[N];

void update(int x, int delta) {
	for(; x <= n; x += x & -x) tree[x] += delta;
}

ll query(int x) {
	ll sum = 0;
	for(; x > 0; x -= x & -x) sum += tree[x];
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}

	while(q--) {
		cin >> t >> l >> r;
		if(t == 1) {
			update(l, r - a[l]);
			a[l] = r;
		} else cout << query(r) - query(l - 1) << "\n";
	}
}