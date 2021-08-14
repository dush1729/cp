#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n, q, l, r, c;
	cin >> n >> q;
	vector <pair <int, int>> s[n], e[n];
	for(int i = 0; i < q; i++) {
		cin >> l >> r >> c;
		l--, r--;
		s[l].push_back({i, c});
		if(r != n - 1) e[r + 1].push_back({i, c});
	}

	multiset <pair <int, int>> ms;
	for(int i = 0; i < n; i++) {
		for(auto &[q, c]: e[i]) ms.erase({q, c});
		for(auto &[q, c]: s[i]) ms.insert({q, c});
		if(ms.empty()) {
			cout << 0;
		} else {
			cout << (--ms.end())->second;
		}
		cout << "\n";
	}
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