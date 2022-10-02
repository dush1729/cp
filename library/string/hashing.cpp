/*
Problems
https://leetcode.com/problems/longest-palindromic-substring

1 based indexing
*/

const int BASE = 128;
const vector <int> MODS = {342876881, 573161801};
ll n, lh[2][N], rh[2][N], p[2][N];

ll fix(ll x, ll MOD) {
	x %= MOD;
	return x < 0 ? x + MOD : x;
}

void precompute(const string &a) {
	n = a.size();
	for(int i = 0; i < 2; i++) p[i][0] = 1;

	for(int i = 0; i < MODS.size(); i++) {
		for(int j = 0; j < n; j++) {
			lh[i][j + 1] = (lh[i][j] * BASE + a[j]) % MODS[i];
			p[i][j + 1] = p[i][j] * BASE % MODS[i];
		}
		for(int j = n - 1, k = 0; j >= 0; j--, k++) {
			rh[i][k + 1] = (rh[i][k] * BASE + a[j]) % MODS[i];
		}
	}
}

ll getl(int l, int r, int i) {
	return fix(lh[i][r] - lh[i][l - 1] * p[i][r - l + 1], MODS[i]);
}

ll getr(int l, int r, int i) {
	return fix(rh[i][n - l + 1] - rh[i][n - r] * p[i][r - l + 1], MODS[i]);
}

bool equal(int a, int b, int la, int lb) {
	for(int i = 0; i < MODS.size(); i++) {
		if(getl(a, a + la - 1, i) != getl(b, b + lb - 1, i)) return false;
	}
	return true;
}
bool equal(int a, int b, int l) {return equal(a, b, l, l);}

bool pal(int l, int r) {
	for(int i = 0; i < MODS.size(); i++) {
		if(getl(l, r, i) != getr(l, r, i)) return false;
	}
	return true;
}