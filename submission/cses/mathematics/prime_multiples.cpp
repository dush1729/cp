#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 22;

ll n, k, a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i = 0; i < k; i++) cin >> a[i];

	ll ans = 0;
	for(int mask = 0; mask < (1 << k); mask++) {
		ll p = 1;
		bool odd = false;
		for(int i = 0; i < k; i++) {
			if(mask & (1 << i)) {
				if(p > 1. * n / a[i]) {
					p = n + 1;
					break;
				} else {
					p *= a[i];
				}
				odd ^= 1;
			}
		}

		if(odd) ans -= n / p;
		else ans += n / p;
	}

	cout << n - ans;
}