#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;

vector <string> moveup(vector <string> a) {
	int n = a.size(), m = a[0].size();
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int r = i; r > 0 && a[r][j] == 'O' && a[r - 1][j] != '#'; r--) {
				swap(a[r][j], a[r - 1][j]);
			}
		}
	}
	return a;
}
vector <string> moveleft(vector <string> a) {
	int n = a.size(), m = a[0].size();
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < m; j++) {
			for(int c = j; c > 0 && a[i][c] == 'O' && a[i][c - 1] != '#'; c--) {
				swap(a[i][c], a[i][c - 1]);
			}
		}
	}
	return a;
}
vector <string> movedown(vector <string> a) {
	int n = a.size(), m = a[0].size();
	for(int i = n - 2; i >= 0; i--) {
		for(int j = 0; j < m; j++) {
			for(int r = i; r + 1 < n && a[r][j] == 'O' && a[r + 1][j] != '#'; r++) {
				swap(a[r][j], a[r + 1][j]);
			}
		}
	}
	return a;
}
vector <string> moveright(vector <string> a) {
	int n = a.size(), m = a[0].size();
	for(int i = 0; i < n; i++) {
		for(int j = m - 2; j >= 0; j--) {
			for(int c = j; c + 1 < m && a[i][c] == 'O' && a[i][c + 1] != '#'; c++) {
				swap(a[i][c], a[i][c + 1]);
			}
		}
	}
	return a;
}

void run_test(int testcase) {
	int n = 100;

	vector <string> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	auto rotate = [&]() {
		a = moveup(a);
		a = moveleft(a);
		a = movedown(a);
		a = moveright(a);
	};
	auto calc = [&]() {
		ll m = a[0].size(), ans = 0;
		for(int j = 0; j < m; j++) {
			for(int i = 0; i < n; i++) {
				if(a[i][j] == 'O') ans += n - i;
			}
		}
		return ans;
	};

	map <vector <string>, int> s;
	int tym = 0;
	while(s.find(a) == s.end()) {
		s[a] = tym++;
		rotate();
	}

	int cycle_len = tym - s[a];
	int times = 1000000000 - s[a];
	times %= cycle_len;
	for(int it = 0; it < times; it++) {
		rotate();
	}

	cout << calc();
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