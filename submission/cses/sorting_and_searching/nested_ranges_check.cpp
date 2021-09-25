#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, N = 2e5 + 2;

struct range {
	int l, r, i;
	bool operator <(const range &rhs) const {
		if(r != rhs.r) return r < rhs.r;
		return l > rhs.l;
	}
};

void run_test(int testcase) {
	int n;
	cin >> n;
	vector <range> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].i = i;
	}

	sort(a.begin(), a.end());

	vector <int> ans1(n), ans2(n);
	priority_queue <pair <int, int>> pq;
	int lMax = INT_MIN;
	for(auto &[l, r, i]: a) {
		if(lMax >= l) {
			ans1[i] = 1;
		}
		while(!pq.empty() && pq.top().first >= l) {
			ans2[pq.top().second] = 1;
			pq.pop();
		}
		pq.push({l, i});
		lMax = max(lMax, l);
	}

	for(int &x: ans1) cout << x << " "; cout << "\n";
	for(int &x: ans2) cout << x << " "; cout << "\n";
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