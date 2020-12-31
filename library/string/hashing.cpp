/*
Problems
https://www.interviewbit.com/problems/longest-palindromic-substring
*/

#define ll long long

class Hashing {

	const int BASE = 256;
	const vector <int> MODS = {1000000007, 573161801};

	int n;
	string a;
	vector <vector <ll>> lh, rh, p;

public:

	void calculate_hashes() {
		lh.clear();
		rh.clear();
		p.clear();

		for(int mod: MODS) {
			lh.push_back({0});
			p.push_back({1});
			for(int x: a) {
				ll v = lh.back().back() * BASE + x;
				lh.back().push_back(v % mod);
				p.back().push_back(p.back().back() * BASE % mod);
			}

			reverse(a.begin(), a.end());
			rh.push_back({0});
			for(int x: a) {
				ll v = rh.back().back() * BASE + x;
				rh.back().push_back(v % mod);
			}
			reverse(a.begin(), a.end());
		}
	}

	// pal(2 * l + 2, 2 * r + 2)
	// a[l, r] is palindrome(1 based indexing)
	bool pal(int l, int r) {
		for(int i = 0; i < MODS.size(); i++) {
			ll lhash = lh[i][r] - lh[i][l - 1] * p[i][r - l + 1];
			lhash %= MODS[i];
			if(lhash < 0) lhash += MODS[i];

			ll rhash = rh[i][n - l + 1] - rh[i][n - r] * p[i][r - l + 1];
			rhash %= MODS[i];
			if(rhash < 0) rhash += MODS[i];

			if(lhash != rhash) return false;
		}
		return true;
	}

	string longest_pal() {
		int ans = 0, idx = -1;
		for(int i = 1; i + 1 < n; i++) {
			int lo = 1, hi = min(i + 1, n - i), len = -1;
			while(lo <= hi) {
				int mid = (lo + hi) >> 1;
				if(pal(i - mid + 1, i + mid - 1)) lo = mid + 1, len = mid;
				else hi = mid - 1;
			}

			int start = i - len + 1;
			if(a[i] == '#') len = (len + 1) / 2;
			else len = (len - 2) / 2;
			if(ans < len) {
				ans = len;
				idx = start;
			}
		}

		string s;
		while(s.size() < ans) {
			if(a[idx] != '#') {
				s += a[idx];
				idx++;
			}
		}
		return s;
	}


	void init(string &s) {
		a = "#";
		for(char &c: s) {
			a += c;
			a += "#";
		}

		n = a.size();
		calculate_hashes();
	}
};