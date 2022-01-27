//https://atcoder.jp/contests/abc235/tasks/abc235_f
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0, N = 1e4, M = 1024, MOD = 998244353;

string a;
int m;

void run_test(int testcase) {
	cin >> a;
	int l;
	cin >> l;
	while(l--) {
		int x;
		cin >> x;
		m ^= (1 << x);
	}

	int ans = 0;

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