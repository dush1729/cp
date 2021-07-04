#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 20, K = 170;

/*
k = min(k, 9 * 18)
dp[i][k]
0 <= i < 18 && k <= 162


0000010929
00001111929
1000283


k <= 9 * 18 was wrong!
k <= min(k, 9 ^ 18) is right! :(
*/

ll n, p, dp[N][K][2][2], cache[N][K][2][2];
string s;

ll f(int i, int k, int non_zero, int strict) {
	//cout << i << " " << k << endl;
	if(i == s.size()) return 1;

	ll &ans = dp[i][k][non_zero][strict];
	if(cache[i][k][non_zero][strict]) return ans;
	cache[i][k][non_zero][strict] = 1;

	for(int d = 0; d < 10; d++) {
		ll t = k * d, flag = non_zero;
		if(!non_zero && d == 0) t = 1;
		if(!non_zero && d > 0) flag = 1;
		if(t > p) continue;

	//cout << i << " " << k << " " << strict << " " << t <<  endl;
		if(d < s[i] - '0') {
			ans += f(i + 1, t, flag, 0);
		} else if(d == s[i] - '0' || !strict) {
			ans += f(i + 1, t, flag, strict);
		}
	}
	return ans;
}

void run_test(int testcase) {
	cin >> n >> p;
	s = to_string(n);
	cout << f(0, 1, 0, 1) - 1;
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