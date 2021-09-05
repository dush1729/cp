#include "bits/stdc++.h"
#pragma GCC target("popcnt")
using namespace std;
#define ll long long
const int areTests = 0, N = 2e4, B = 30;

bitset <B> a[N];

void run_test(int testcase) {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < k; j++) {
			if(s[j] == '1') a[i][j] = 1;
		}
	}

	int ans = k;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			ans = min(ans, (int)(a[i] ^ a[j]).count());
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