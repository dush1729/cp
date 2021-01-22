#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 42;

int n, s, x;
vector <int> a[2];
vector <ll> v[2];
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a[i % 2].push_back(x);
	}

	for(int k = 0; k < 2; k++) {
		for(int mask = 0; mask < (1 << a[k].size()); mask++) {
			long long s = 0;
			for(int i = 0; i < a[k].size(); i++) {
				if(mask & (1 << i)) s += a[k][i];
			}
			v[k].push_back(s);
		}
	}

	sort(v[1].begin(), v[1].end());
	for(ll x: v[0]) {
		ans += upper_bound(v[1].begin(), v[1].end(), s - x) -
				lower_bound(v[1].begin(), v[1].end(), s - x);
	}
	cout << ans;
}