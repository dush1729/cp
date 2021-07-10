#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

string longest_common_subsequence(string &a, string &b) {
	int n = a.size(), m = b.size();
	vector dp(n + 1, vector (m + 1, 0));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string ans;
	for(int i = n, j = m; i > 0 && j > 0; ) {
		if(dp[i - 1][j] == dp[i][j]) i--;
		else if(dp[i][j - 1] == dp[i][j]) j--;
		else {
			ans += a[i - 1];
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void run_test(int testcase) {
	string s, t;
	cin >> s >> t;
	cout << longest_common_subsequence(s, t);
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