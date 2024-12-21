#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, N = 50;

string a[N];

void run_test(int testcase) {
	for(int i = 0; i < N; i++) cin >> a[i];
	map <char, vector <pair <int, int>>> m;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(a[i][j] != '.') m[a[i][j]].push_back({i, j});
		}
	}

	set <pair <int, int>> s;
	auto in = [&](int x, int y) {
		return min(x, y) >= 0 && max(x, y) < N;
	};

	auto add = [&](int x, int y) {
		if(in(x, y)) s.insert({x, y});
	};

	for(auto &[_, v]: m) {
		int n = v.size();
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				const auto &[x1, y1] = v[i];
				const auto &[x2, y2] = v[j];
				add(x1 + x1 - x2, y1 + y1 - y2);
				add(x2 + x2 - x1, y2 + y2 - y1);
			}
		}
	}
	cout << s.size();
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