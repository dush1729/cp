#include "bits/stdc++.h"
using namespace std;

const int N = 4e5 + 20;

int n, x, y, f[N], ans;
vector <int> a;

int compress(vector <int> &v) {
	if(v.empty()) return 0;
	vector <int> s = v;
	sort(s.begin(), s.end());
	s.resize(unique(s.begin(), s.end()) - s.begin());

	int mx = 1;
	for(int &x: v) {
		x = lower_bound(s.begin(), s.end(), x) - s.begin() + 1;
		mx = max(mx, x);
	}
	return mx;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		a.push_back(x);
		a.push_back(y);
	}

	compress(a);
	for(int i = 0; i < n; i++) {
		f[a[i << 1]]++;
		f[a[(i << 1) + 1] + 1]--;
	}

	for(int i = 1; i < N; i++) {
		f[i] += f[i - 1];
		ans = max(ans, f[i]);
	}
	cout << ans;
}