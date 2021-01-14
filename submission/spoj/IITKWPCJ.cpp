#include "bits/stdc++.h"
using namespace std;

int t;
string a, b;

bool ok(string a, string b) {
	int n = a.size(), m = b.size();
	if(n < m) {
		swap(a, b);
		swap(n, m);
	}

	for(int i = 0; i < n; i++) {
		if(a[i] != b[i % m]) return false;
	}
	int r = n % m;
	return r == 0 || ok(a.substr(n - r), b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> a >> b;
		cout << (ok(a, b) ? "YES": "NO") << "\n";
	}
}