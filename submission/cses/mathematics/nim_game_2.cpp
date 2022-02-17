#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 1;



void run_test(int testcase) {
	int n, x, xr = 0;
	cin >> n;
	while(n--) cin >> x, xr ^= (x % 4);
	cout << (xr ? "first" : "second") << "\n";
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