#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n;
	cin >> n;
	vector <int> a(n), idx(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		idx[a[i] - 1] = i;
	}

	int ans = 0;
	for(int i = 0; i < n; ) {
		int pv = -1;
		for( ; i < n && idx[i] > pv; pv = idx[i], i++) ;
		ans++;
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