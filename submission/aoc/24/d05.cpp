#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, RULES = 1176, UPDATES = 185;



void run_test(int testcase) {
	map <int, vector <int>> pv;
	for(int i = 0; i < RULES; i++) {
		int a, b;
		cin >> a >> b;
		pv[a].push_back(b);
	}

	int ans = 0;
	for(int i = 0; i < UPDATES; i++) {
		int n, ok = 1;
		cin >> n;

		vector updates(n, 0);
		set <int> vis;
		for(auto &x: updates) {
			cin >> x;
			if(pv.find(x) != pv.end()) {
				for(const auto &y: pv[x]) {
					if(vis.find(y) != vis.end()) {
						ok = 0;
					}
				}
			}
			vis.insert(x);
		}

		if(ok) ans += updates[n / 2];
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