#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 1;



void run_test(int testcase) {
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	cout << "Case #" << testcase << ": ";
	if(min(a, b) < n + m - 1) {
		cout << "Impossible\n";
		return;
	}

	cout << "Possible\n";
	vector grid(n, vector (m, 1));
	grid[0][0] = a - (n + m - 1) + 1;
	grid[0][m - 1] = b - (n + m - 1) + 1;
	for(auto &v: grid) {
		for(int &x: v) cout << x << " ";
		cout << "\n";
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