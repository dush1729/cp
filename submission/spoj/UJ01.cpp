#include "bits/stdc++.h"
using namespace std;
#define ll long long

int t, a, b, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> a >> b >> n;

		int lcm = a * b / __gcd(a, b);
		ll lo = 1, hi = 1e18, ans = -1;
		while(lo <= hi) {
			ll mid = (lo + hi) >> 1;

			ll m = mid / a + mid / b - mid / lcm;
			if(m >= n) hi = mid - 1, ans = mid;
			else lo = mid + 1;
		}

		cout << ans << "\n";
	}
}