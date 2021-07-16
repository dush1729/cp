#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, BASE = 26, MOD = 28569017;



void run_test(int testcase) {
	int n;
	string needle, haystack;

	while(cin >> n) {
		cin >> needle >> haystack;
		if(needle.size() > haystack.size()) {
			continue;
		}

		int hash = 0, p = 1;
		for(int i = 0; i < needle.size(); i++) {
			hash = (hash * BASE + needle[i] - 'a') % MOD;
			if(i + 1 != needle.size()) p = (p * BASE) % MOD;
		}

		for(int x = 0, i = 0; i < haystack.size(); i++) {
			if(i >= needle.size()) x -= (p * (haystack[i - needle.size()] - 'a')) % MOD;
			x %= MOD;
			if(x < 0) x += MOD;
			x = (x * BASE + haystack[i] - 'a') % MOD;
			if(i >= needle.size() - 1 && x == hash) cout << i - needle.size() + 1 << "\n";
		}
	}
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