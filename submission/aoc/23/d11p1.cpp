#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, N = 140;



void run_test(int testcase) {
	vector <string> a;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		a.push_back(s);
		if(count(s.begin(), s.end(), '#') == 0) {
			a.push_back(s);
		}
	}

	for(int j = 0; j < a[0].size(); j++) {
		bool hash = false;
		for(int i = 0; i < a.size(); i++)
			if(a[i][j] == '#') hash = true;

		if(not hash) {
			for(int i = 0; i < a.size(); i++) {
				a[i] = a[i].substr(0, j) + "." + a[i].substr(j);
			}
			j++;
		}
	}

	vector <pair <int, int>> arr;
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < a[i].size(); j++) {
			if(a[i][j] == '#') arr.push_back({i, j});
		}
	}
	int ans = 0;
	for(int i = 0; i < arr.size(); i++) {
		for(int j = i + 1; j < arr.size(); j++) {
			ans += abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
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