#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;



void run_test(int testcase) {
	vector dp(209, 1ll);
	for(int card = 1; card <= 208; card++) {
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

		ll cnt = 0;
		while(i < a.size()) {
			for( ; !isdigit(a[i]); i++) ;

			string num;
			for( ; isdigit(a[i]); i++) num += a[i];
			int x = stoi(num);
			if(win.find(x) != win.end()) {
				cnt++;
			}
		}

		for(int i = card + 1; i <= card + cnt; i++) dp[i] += dp[card];
	}

	ll ans = 0;
	for(int i = 1; i <= 208; i++) ans += dp[i];
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