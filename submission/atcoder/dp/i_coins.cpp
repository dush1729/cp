#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n;
	cin >> n;
	vector <double> prob(n);
	for(auto &x: prob) cin >> x;

	vector <vector <double>> dp(n + 1, vector <double> (n + 1, 0));

	dp[0][0] = 1;
	for(int total = 0; total < n; total++) {
		for(int heads = 0; heads <= total; heads++) {
			int tails = total - heads;
			double probHead = prob[total], probTail = 1 - prob[total];
			dp[total + 1][heads + 1] += dp[total][heads] * probHead;
			dp[total + 1][heads] += dp[total][heads] * probTail;
		}
	}

	double ans = 0;
	for(int heads = (n + 2) / 2; heads <= n; heads++) {
		ans += dp[n][heads];
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