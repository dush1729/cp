#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;



void run_test(int testcase) {
	string a;
	cin >> a;
	map <string, string> l, r;
	for(int i = 0; i < 3; i++) {
		string s, sl, sr;
		cin >> s >> sl >> sr;
		l[s] = sl, r[s] = sr;
	}

	string cur = "AAA";
	int i = 0, ans = 0;
	while(cur != "ZZZ") {
		if(a[i] == 'L') {
			cur = l[cur];
		} else {
			cur = r[cur];
		}
		i++;
		if(i == a.size()) i = 0;
		ans++;
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