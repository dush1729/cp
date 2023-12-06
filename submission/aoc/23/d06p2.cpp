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

	string timez;
	for(auto &x: t) timez += to_string(x);
	string distz;
	for(auto &x: d) distz += to_string(x);

	ll tim = stoll(timez), dis = stoll(distz);

	ll ans = 0;
	for(ll tym = 1; tym < tim; tym++) {
		ll r = tim - tym;
		ll dist = r * tym;
		if(dist > dis) ans++;
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