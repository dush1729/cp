#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = custom_hash>
using hash_map = gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = custom_hash>
using hash_set = hash_map<K, null_type, Hash>;

void run_test(int testcase) {
	ll n, ans = 0;
	cin >> n;
	vector a(n, 0);
	for(auto &x: a) cin >> x;

	hash_set <int> s;
	for(int r = 0, l = 0; r < n; r++) {
		if(!s.insert(a[r]).second) {
			while(a[l] != a[r]) {
				s.erase(a[l]);
				l++;
			}
			l++;
		}
		ans += r - l + 1;
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