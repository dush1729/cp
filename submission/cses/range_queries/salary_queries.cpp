#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n, q;
	cin >> n >> q;
	vector a(n, 0);
	ordered_set <pair <int, int>> s;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert({a[i], i});
	}

	while(q--) {
		char c;
		int x, y;
		cin >> c >> x >> y;

		if(c == '!') {
			x--;
			s.erase(s.find({a[x], x}));
			a[x] = y;
			s.insert({a[x], x});
		} else {
			cout << s.order_of_key({y + 1, 0}) - s.order_of_key({x, 0}) << "\n";
		}
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