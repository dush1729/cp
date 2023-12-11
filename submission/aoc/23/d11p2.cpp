#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, N = 140;

ll f(vector <int> &a, vector <int> &dp) {
	ll ans = 0;
	for(int i = 0; i < a.size(); i++) {
		for(int j = i + 1; j < a.size(); j++) {
			ll l = a[i], r = a[j], cnt = 0;
			for(int k = l; k <= r; k++)
				if(dp[k]) cnt++;
			ans += cnt * 1000000 - cnt + r - l;
		}
	}
	return ans;
}

void run_test(int testcase) {
	vector <string> a;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		a.push_back(s);
	}

	vector <int> vx, vy;
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < a[i].size(); j++) {
			if(a[i][j] == '#') {
				vx.push_back(i);
				vy.push_back(j);
			}
		}
	}

	vector r(N, 0), c(N, 0);
	for(int i = 0; i < a.size(); i++) {
		bool hash = false;
		for(int j = 0; j < a[i].size(); j++) {
			if(a[i][j] == '#') hash = true;
		}
		if(not hash) r[i] = 1;
	}
	for(int j = 0; j < a[0].size(); j++) {
		bool hash = false;
		for(int i = 0; i < a.size(); i++) {
			if(a[i][j] == '#') hash = true;
		}
		if(not hash) c[j] = 1;
	}

	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	cout << f(vx, r) + f(vy, c);
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