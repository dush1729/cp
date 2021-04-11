#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 1;



void run_test(int testcase) {
	cout << "Case #" << testcase << ": ";
}

int main() {
	ios::sync_with_stdio(0);
	#ifndef LOCAL
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);

	int t = 1;
	if(areTests) cin >> t;
	for(int i = 1; i <= t; i++) {
		run_test(i);
	}
}