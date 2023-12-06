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

void run_test(int testcase) {
	string str;
	getline(cin, str);
	auto t = split(str);
	getline(cin, str);
	auto d = split(str);

	ll ans = 1;
	for(int i = 0; i < t.size(); i++) {
		ll ways = 0;
		for(int tym = 1; tym < t[i]; tym++) {
			ll r = t[i] - tym;
			ll dist = r * tym;
			if(dist > d[i]) ways++;
		}
		ans *= ways;
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