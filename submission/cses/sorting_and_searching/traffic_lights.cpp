#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int x, n;
	cin >> x >> n;

	x *= 2;
	set <int> vis = {0, x + 1};
	multiset <int> seg = {x};
	while(n--) {
		cin >> x;
		x = x * 2 + 1;

		auto itr = vis.lower_bound(x), itl = prev(itr);
		int l = *itl, r = *itr;
		seg.erase(seg.find(r - l - 1));
		vis.insert(x);
		seg.insert(x - l - 1), seg.insert(r - x - 1);

		cout << (*seg.rbegin() + 1) / 2 << " ";
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