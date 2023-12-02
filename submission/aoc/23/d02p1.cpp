#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;



void run_test(int testcase) {
	ll ans = 0;
	for(int inp = 0; inp < 100; inp++) {
		string a;
		getline(cin, a);

		int i = 0;
		while(a[i] != ':') i++;
		i++;// ':'
		i++;// ' '

		map <string, int> m;
		while(i < a.size()) {
			string num;
			while(isdigit(a[i])) num += a[i], i++;
			i++;// ' '

			string col;
			while(isalpha(a[i])) col += a[i], i++;
			i++;// ','
			i++;// ' '

			m[col] = max(m[col], stoi(num));
		}
		ans += m["red"] * m["green"] * m["blue"];
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