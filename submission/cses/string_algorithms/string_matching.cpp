#include "bits/stdc++.h"
using namespace std;

const int BASE = 75, START = 'a', MOD = 327458127;

string a, b;
int n, m, ha, hb, p = 1;

int add(int x, int y) {
	return (0ll + x + y) % MOD;
}

int mul(int x, int y) {
	return (1ll * x * y) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	n = a.size(), m = b.size();

	if(n < m) {
		cout << 0;
		return 0;
	}

	for(int i = 0; i < m; i++) {
		hb = add(mul(hb, BASE), b[i] - START);
		if(i + 1 != b.size()) p = mul(p, BASE);
	}
 
	for(int i = 0; i < m; i++) {
		ha = add(mul(ha, BASE), a[i] - START);
	}

	int ans = (ha == hb);
	for(int i = m; i < n; i++) {
		ha = (ha - mul(a[i - m] - START, p) + MOD) % MOD;
		ha = add(mul(ha, BASE), a[i] - START);
		ans += (ha == hb);
	}

	cout << ans;
}