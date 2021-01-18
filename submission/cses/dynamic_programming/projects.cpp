#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 20;

int n;
struct project {
	int l, r, v;
} p[N];
long long dp[N], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> p[i].l >> p[i].r >> p[i].v;
	}

	sort(p, p + n, [&](const auto &p1, const auto &p2) {return p1.r < p2.r;});

	for(int i = 0; i < n; i++) {
		auto [l, r, v] = p[i];
		dp[i] = v;
		if(i > 0) dp[i] = max(dp[i], dp[i - 1]);

		int lo = 0, hi = i - 1, idx = -1;
		while(lo <= hi) {
			int mid = (lo + hi) >> 1;
			if(p[mid].r < l) lo = mid + 1, idx = mid;
			else hi = mid - 1;
		}

		if(idx != -1) {
			dp[i] = max(dp[i], dp[idx] + v);
		}

		ans = max(ans, dp[i]);
	}

	cout << ans;
}