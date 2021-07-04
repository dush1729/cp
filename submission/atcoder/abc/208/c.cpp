#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for(ll &x: a) cin >> x;

	vector <ll> ans(n);
	for(int i = 0; i < n; i++) ans[i] = k / n;

	vector <int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](const auto &i, const auto &j) {
		return a[i] < a[j];
	});

	k %= n;
	for(int i = 0; i < n && k > 0; i++, k--) ans[order[i]]++;
	for(ll &x: ans) cout << x << " ";
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