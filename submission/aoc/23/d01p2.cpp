#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;

vector <string> digits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void run_test(int testcase) {
	string s;
	int ans = 0;
	while(getline(cin, s)) {
		char firstDig = '$', lastDig = '$';
		for(int i = 0; i < s.size(); i++) {
			for(int d = 0; d < 9; d++) {
				auto subs = s.substr(i, digits[d].size());
				if(subs != digits[d]) continue;
				if(firstDig == '$') firstDig = '0' + d + 1;
				lastDig = '0' + d + 1;
			}
			if(isdigit(s[i])) {
				if(firstDig == '$') firstDig = s[i];
				lastDig = s[i];
			}
		}

		if(firstDig == '$') cout << s << endl;

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