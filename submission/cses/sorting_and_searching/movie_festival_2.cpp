#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;

struct movie {
	int start, end;
	bool operator<(const movie &rhs) const {
		return end < rhs.end;
	}
};

void run_test(int testcase) {
	int n, k;
	cin >> n >> k;
	vector <movie> movies(n);
	for(auto &[start, end]: movies) cin >> start >> end;
	sort(movies.begin(), movies.end());

	multiset <int> ms;
	for(int i = 0; i < k; i++) ms.insert(0);

	int ans = 0;
	for(const auto &[start, end]: movies) {
		auto it = ms.upper_bound(start);
		if(it != ms.begin()) {
			ms.erase(prev(it));
			ms.insert(end);
			ans++;
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