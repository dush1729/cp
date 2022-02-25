#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n;
	cin >> n;
	set <int> s;
	for(int i = 1; i <= n; i++) s.insert(i);

	if(n == 1) {
		cout << "1";
		return;
	}

	for(int x = 2; !s.empty(); ) {
		cout << x << " ";
		s.erase(x);
		if(s.empty()) break;

		auto it = s.lower_bound(x);
		if(it == s.end()) it = s.begin();
		it++;
		if(it == s.end()) it = s.begin();

		x = *it;
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