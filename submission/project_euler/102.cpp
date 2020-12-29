#include "bits/stdc++.h"
using namespace std;

const int n = 1000;

#define pi pair <int, int>

int ans;
pi a, b, c, zero = {0, 0};

int area(const pi &a, const pi &b, const pi &c) {
	return abs(a.first * (b.second - c.second) + b.first * (c.second - a.second)
		+ c.first * (a.second - b.second));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 0; i < n; i++) {
		cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
		int a1 = area(a, b, zero);
		int a2 = area(a, c, zero);
		int a3 = area(b, c, zero);
		int total = area(a, b, c);
		if(abs(total - (a1 + a2 + a3)) < 1e-6) ans++;
	}

	cout << ans;
}