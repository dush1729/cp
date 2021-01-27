#include "bits/stdc++.h"
using namespace std;

int k;
string a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(1729) {
		cin >> k >> ws;
		if(k == 0) break;
		getline(cin, a);

		int n = a.size(), ans = 0;
		unordered_map <int, int> m;
		for(int r = 0, l = 0; r < n; r++) {
			m[a[r]]++;

			for( ; m.size() == k + 1; l++) {
				if(--m[a[l]] == 0) m.erase(a[l]);
			}

			ans = max(ans, r - l + 1);
		}

		cout << ans << "\n";
	}
}