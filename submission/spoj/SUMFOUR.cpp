#include "bits/stdc++.h"
using namespace std;

const int N = 3e3 + 20;

int n, a[N], b[N], c[N], d[N], ans;
vector <int> v1, v2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			v1.push_back(a[i] + b[j]);
			v2.push_back(c[i] + d[j]);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());

	for(int i = 0, j = 0; i < v1.size(); ) {
		int l1 = 0;
		while(i + l1 < v1.size() and v1[i + l1] == v1[i]) l1++;

		while(j < v2.size() and v2[j] + v1[i] > 0) j++;

		if(v1[i] + v2[j] == 0)
		{
			int l2 = 0;
			while(j + l2 < v2.size() and v2[j + l2] == v2[j]) l2++;

			ans += 1ll * l1 * l2;

			j += l2;
		}

		i += l1;
	}
	cout << ans;
}