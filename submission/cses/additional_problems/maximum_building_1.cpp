#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n, m, ans = 0;
	cin >> n >> m;

	vector b(m, 0);
	while(n--) {
		string a;
		cin >> a;
		for(int j = 0; j < m; j++) {
			if(a[j] == '.') b[j]++;
			else b[j] = 0;
		}

		vector l(m, -1), r(m, m), v(0, 0);
		for(int i = 0; i < m; i++) {
			while(!v.empty() && b[v.back()] >= b[i]) v.pop_back();
			if(!v.empty()) l[i] = v.back();
			v.push_back(i);
		}
		v.clear();
		for(int i = m - 1; i >= 0; i--) {
			while(!v.empty() && b[v.back()] > b[i]) v.pop_back();
			if(!v.empty()) r[i] = v.back();
			ans = max(ans, (r[i] - l[i] - 1) * b[i]);
			v.push_back(i);
		}
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