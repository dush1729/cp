/*
Problems
https://leetcode.com/problems/longest-palindromic-substring
*/

const int BASE = 128;
const vector <int> MODS = {342876881, 573161801};
ll lh[2][N], rh[2][N], p[2][N];

struct HASHING {
	int n;

	HASHING(const string &a) {
		n = a.size();
		for(int i = 0; i < 2; i++) p[i][0] = 1;

		for(int i = 0; i < MODS.size(); i++) {
			for(int j = 0; j < a.size(); j++) {
				lh[i][j + 1] = (lh[i][j] * BASE + a[j]) % MODS[i];
				p[i][j + 1] = p[i][j] * BASE % MODS[i];
			}
			for(int j = a.size() - 1, k = 0; j >= 0; j--, k++) {
				rh[i][k + 1] = (rh[i][k] * BASE + a[j]) % MODS[i];
			}
		}
	}

	ll getl(int l, int r, int i) {
		ll lhash = lh[i][r] - lh[i][l - 1] * p[i][r - l + 1];
		lhash %= MODS[i];
		if(lhash < 0) lhash += MODS[i];
		return lhash;
	}

	ll getr(int l, int r, int i) {
		ll rhash = rh[i][n - l + 1] - rh[i][n - r] * p[i][r - l + 1];
		rhash %= MODS[i];
		if(rhash < 0) rhash += MODS[i];
		return rhash;
	}

	bool equal(int a, int b, int l) {
		for(int i = 0; i < MODS.size(); i++) {
			if(getl(a, a + l - 1, i) != getl(b, b + l - 1, i)) return false;
		}
		return true;
	}

	bool pal(int l, int r) {
		for(int i = 0; i < MODS.size(); i++) {
			if(getl(l, r, i) != getr(l, r, i)) return false;
		}
		return true;
	}
};