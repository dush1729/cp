#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

vector <int> f = {1, 1};

void run_test(int testcase) {
	int n, ans = 0;
	cin >> n;

	int i = f.size() - 1;
	while(n > 0) {
		while(f[i] > n) i--;
		ans += n / f[i];
		n -= (n / f[i]) * f[i];
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	#ifndef DUSH1729
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);

	for(int i = 2; i <= 10; i++) f.push_back(f.back() * i);

	int t = 1;
	if(areTests) cin >> t;
	for(int i = 1; i <= t; i++) {
		run_test(i);
	}
}