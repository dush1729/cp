#include "bits/stdc++.h"
using namespace std;

int n, x;
multiset <int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while(n--) {
		cin >> x;

		auto it = s.upper_bound(x);
		if(it != s.end()) {
			s.erase(it);
		}
		s.insert(x);
	}
	cout << s.size();
}