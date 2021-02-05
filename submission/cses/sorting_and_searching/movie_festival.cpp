#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 20;

int n, ans;
pair <int, int> p[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i].second >> p[i].first;

	sort(p, p + n);

	for(int i = 0; i < n;) {
		auto &[end, _] = p[i];
		i++;
		while(i < n && p[i].second < end) i++;
		ans++;
	}

	cout << ans;
}