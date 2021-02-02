#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 20;

int n, k, a[N];
map <int, int> m;
long long ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int r = 0, l = 0; r < n; r++) {
		m[a[r]]++;
		for( ; l < r && m.size() == k + 1; l++) {
			m[a[l]]--;
			if(m[a[l]] == 0) {
				m.erase(a[l]);
			}
		}

		ans += r - l + 1;
	}
	cout << ans;
}