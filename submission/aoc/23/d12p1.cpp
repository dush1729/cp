#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;

vector <ll> split(string a) {
	vector <ll> v;
	for(int i = 0; i < a.size(); ) {
		while(i < a.size() && !isdigit(a[i])) i++;
		if(i == a.size()) break;

		string s;
		while(i < a.size() && isdigit(a[i])) s += a[i], i++;
		v.push_back(stoll(s));
	}
	return v;
}

ll ways(string a, vector <ll> v) {
	vector <ll> b;
	int cnt = 0;
	for(char &c: a) {
		if(c == '#') {
			cnt++;
		} else {
			if(cnt) b.push_back(cnt);
			cnt = 0;
		}
	}
	if(cnt) b.push_back(cnt);
	return b == v;
}

void run_test(int testcase) {
	int ans = 0;
	for(int it = 0; it < 1000; it++) {
		string a, b;
		cin >> a >> b;

		vector <int> v;
		for(int i = 0; i < a.size(); i++) {
			if(a[i] == '?') v.push_back(i);
		}
		auto cnt = split(b);

		ll res = 0;
		for(int mask = 0; mask < (1 << v.size()); mask++) {
			auto s = a;
			for(int i = 0; i < v.size(); i++) {
				if(mask & (1 << i)) {
					s[v[i]] = '.';
				} else {
					s[v[i]] = '#';
				}
			}

			res += ways(s, cnt);
		}
		ans += res;
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