#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;



void run_test(int testcase) {
	ll ans = 0;
	for(int loop = 0; loop < 208; loop++) {
		string a;
		getline(cin, a);

		int i = 0;
		for( ; a[i] != ':'; i++) ;
		for( ; !isdigit(a[i]); i++) ;

		unordered_set <int> win;
		while(win.size() < 10) {
			for( ; !isdigit(a[i]); i++) ;

			string num;
			for( ; isdigit(a[i]); i++) num += a[i];
			win.insert(stoi(num));
		}

		ll res = 0;
		while(i < a.size()) {
			for( ; !isdigit(a[i]); i++) ;

			string num;
			for( ; isdigit(a[i]); i++) num += a[i];
			int x = stoi(num);
			if(win.find(x) != win.end()) {
				if(res == 0) res = 1;
				else res *= 2;
			}
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