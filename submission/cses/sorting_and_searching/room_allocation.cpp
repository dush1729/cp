#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

struct customer {
	int l, r, i;
	bool operator <(const customer &rhs) const {
		return l < rhs.l;
	}
};

void run_test(int testcase) {
	int n;
	cin >> n;
	vector <customer> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].i = i;
	}

	sort(a.begin(), a.end());

	int rooms = 0;
	vector <int> ans(n);
	priority_queue <pair <int, int>> pq;
	for(int i = 0; i < n; i++) {
		if(!pq.empty() && -pq.top().first < a[i].l) {
			ans[a[i].i] = ans[pq.top().second];
			pq.pop();
		} else {
			ans[a[i].i] = pq.size() + 1;
		}
		rooms = max(rooms, ans[a[i].i]);
		pq.push({-a[i].r, a[i].i});
	}
	cout << rooms << "\n";
	for(int &x: ans) cout << x << " ";
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