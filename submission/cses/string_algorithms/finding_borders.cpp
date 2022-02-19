#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0, BASE = 26;
const ll MOD = 3'111'335'656'991'251;


void run_test(int testcase) {
	string a;
	cin >> a;

	int n = a.size();
	for(ll i = 0, l = 0, r = 0, p = 1; i + 1 < n; i++) {
		l = (l * BASE + (a[i] - 'a' + 1)) % MOD;
		r = ((a[n - i - 1] - 'a' + 1) * p + r) % MOD;
		if(l == r) cout << i + 1 << " ";

		p = (p * BASE) % MOD;
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