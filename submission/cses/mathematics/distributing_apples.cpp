#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

const int MOD = 1e9 + 7;

int add(int a, int b) {
	return (0ll + a + b) % MOD;
}

int mul(int a, int b) {
	return (1ll * a * b) % MOD;
}

int power(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}

int inverse(int n) {
	return power(n, MOD - 2);
}

struct NCR {
	vector <int> f, invfact;

	NCR(int SZ = 2e6): f(SZ), invfact(SZ) {
		f[0] = 1;
		for(int i = 1; i < SZ; i++) {
			f[i] = mul(f[i - 1], i);
		}

		invfact[SZ - 1] = inverse(f[SZ - 1]);
		for(int i = SZ - 2; i >= 0; i--) {
			invfact[i] = mul(invfact[i + 1], i + 1);
		}
	}

	int c(int n, int r) {
		if(r < 0 or r > n) return 0;
		return mul(f[n], mul(invfact[r], invfact[n - r]));
	}
} ncr;

void run_test(int testcase) {
	int n, m;
	cin >> n >> m;
	cout << ncr.c(n + m - 1, m);
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