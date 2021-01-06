#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 20;

int n, q, x, ans[N], l, r;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		ans[i] = ans[i - 1] ^ x;
	}

	while(q--) {
		cin >> l >> r;
		cout << (ans[r] ^ ans[l - 1]) << "\n";
	}
}