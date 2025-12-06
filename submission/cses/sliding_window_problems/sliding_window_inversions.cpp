#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//https://leetcode.com/problems/minimum-inversion-count-in-subarrays-of-fixed-length
vector <ll> minInversionCount(vector<int>& a, int k) {
	ordered_set <pair <int, int>> s;
	ll inv = 0;

	auto remove = [&](int i) {
		inv -= s.order_of_key({a[i], -1});
		s.erase({a[i], i});

	};

	auto add = [&](int i) {
		inv += s.size() - s.order_of_key({a[i] + 1, -1});
		s.insert({a[i], i});
	};

	vector <ll> ans;
	for(int i = 0; i < a.size(); i++) {
		if(i >= k) remove(i - k);
		add(i);
		if(i >= k - 1) ans.push_back(inv);
	}
	return ans;
}

void run_test(int testcase) {
	int n, k;
	cin >> n >> k;
	vector a(n, 0);
	for(auto &x: a) cin >> x;

	auto ans = minInversionCount(a, k);
	for(const auto &x: ans) cout << x << " ";
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