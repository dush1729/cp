#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

vector <string> getGrayCode(int n) {
	if(n == 1) return {"0", "1"};
	auto v = getGrayCode(n - 1), r = v;
	reverse(r.begin(), r.end());
	for(string &s: r) s = "1" + s;
	for(string &s: v) s = "0" + s;
	v.insert(v.end(), r.begin(), r.end());
	return v;
}

void run_test(int testcase) {
	int n;
	cin >> n;
	auto ans = getGrayCode(n);
	for(string &s: ans) cout << s << "\n";
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