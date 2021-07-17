#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

struct task {
	int duration, deadline;
	bool operator <(const task &rhs) const {
		return duration < rhs.duration;
	}
};

void run_test(int testcase) {
	int n;
	cin >> n;
	vector <task> v(n);
	for(auto &[task, deadline]: v) cin >> task >> deadline;
	sort(v.begin(), v.end());

	ll t = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		t += v[i].duration;
		ans += v[i].deadline - t;
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