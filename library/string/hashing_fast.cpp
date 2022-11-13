/*
Problems
https://leetcode.com/problems/longest-palindromic-substring

1 based indexing

Get 31 bit prime from
https://asecuritysite.com/encryption/random3
*/

const ll BASE = 128, MOD = 342876881, N = 1 << 20;
ll n, lh[N], rh[N], p[N];

ll fix(ll x) {
	x %= MOD;
	return x < 0 ? x + MOD : x;
}

void precompute(const string &a) {
	n = a.size(), p[0] = 1;
	for(int j = 0; j < n; j++) {
		lh[j + 1] = (lh[j] * BASE + a[j]) % MOD;
		p[j + 1] = p[j] * BASE % MOD;
	}
	for(int j = n - 1, k = 0; j >= 0; j--, k++) {
		rh[k + 1] = (rh[k] * BASE + a[j]) % MOD;
	}
}

ll getl(int l, int r) {return fix(lh[r] - lh[l - 1] * p[r - l + 1]);}
ll getr(int l, int r) {return fix(rh[n - l + 1] - rh[n - r] * p[r - l + 1]);}
bool equal(int a, int b, int la, int lb) {return getl(a, a + la - 1) == getl(b, b + lb - 1);}
bool equal(int a, int b, int l) {return equal(a, b, l, l);}
bool pal(int l, int r) {return getl(l, r) == getr(l, r);}