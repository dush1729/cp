#include "bits/stdc++.h"
using namespace std;

int n, x, sum, ans;
multiset <int> s;

int main() {
	scanf("%d%d", &n, &sum);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		s.insert(x);
	}

	while(!s.empty()) {
		int x = *s.begin();
		s.erase(s.begin());

		auto it = s.upper_bound(sum - x);
		if(it != s.begin()) {
			it--;
			s.erase(it);
		}
		ans++;
	}

	cout << ans;
}