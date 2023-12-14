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

void run_test(int testcase) {
	int n = 100;

	vector <string> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a = moveup(a);
	ll m = a[0].size(), ans = 0;
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			if(a[i][j] == 'O') ans += n - i;
		}
	}
	cout << ans;
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