/*
Problems
https://codeforces.com/contest/560/problem/E
*/

const int MOD = 1e9 + 7;

struct NCR {

	vector <int> f, inv;

	int mul(int a, int b) {
		return 1ll * a * b % MOD;
	}

	NCR(int SZ = 1e6): f(SZ), inv(SZ) {
		f[0] = 1;
		for(int i = 1; i < SZ; i++) {
			f[i] = mul(f[i - 1], i);
		}

		inv[SZ - 1] = inverse(f[SZ - 1]);
		for(int i = SZ - 2; i >= 0; i--) {
			inv[i] = mul(inv[i + 1], i + 1);
		}
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

	int c(int n, int r) {
		if(r < 0 or r > n) return 0;
		return mul(f[n], mul(inv[r], inv[n - r]));
	}
};
NCR ncr;