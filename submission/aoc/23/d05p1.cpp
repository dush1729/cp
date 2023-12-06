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
	auto seeds = split(str);

	getline(cin, str);

	while(1729) {
		if(cin.eof()) break;
		getline(cin, str);

		vector <array <ll, 3>> conv;
		while(1729) {
			getline(cin, str);
			if(str == "") break;

			auto arr = split(str);
			ll d = arr[0], s = arr[1], range = arr[2];
			conv.push_back({d, s, range});
		}

		vector res(seeds.size(), LLONG_MAX);
		for(int i = 0; i < seeds.size(); i++) {
			ll x = seeds[i];
			for(const auto &[d, s, range]: conv) {
				if(x >= s && x <= s + range - 1) {
					res[i] = min(res[i], d + (x - s));
				}
			}
		}
		for(int i = 0; i < seeds.size(); i++)
			if(res[i] != LLONG_MAX) seeds[i] = res[i];
	}

	cout << *min_element(seeds.begin(), seeds.end());
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