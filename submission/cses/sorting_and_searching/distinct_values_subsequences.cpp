#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, MOD = 1e9 + 7;

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

struct mi {
 	int v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pwr(mi a, ll p) { return p==0?1:pwr(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pwr(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
mi operator/=(mi &a, mi b) { return a = a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

void run_test(int testcase) {
	int n;
	cin >> n;
	vector a(n, 0);
	for(auto &x: a) cin >> x;

	mi ans = 0, p = 1;
	hash_map <int, mi> dp;
	for(const auto &x: a) {
		dp[x] += 1;
		p /= dp[x];
		ans += p;
		p *= (dp[x] + 1);
	}
	cout << ans.v;
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