#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;



void run_test(int testcase) {
	string s;
	int ans = 0;
	while(getline(cin, s)) {
		char firstDig = '$', lastDig = '$';
		for(const char &c: s) {
			if(isdigit(c)) {
				if(firstDig == '$') firstDig = c;
				lastDig = c;
			}
		}

		string str = string(1, firstDig) + string(1, lastDig);
		ans += stoi(str);
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