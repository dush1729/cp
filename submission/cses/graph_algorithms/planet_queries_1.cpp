#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0;



void run_test(int testcase) {
	int n, q, x, k;
	cin >> n >> q;

	int l = 30;
	vector nxt(l, vector (n, -1));
	for(int i = 0; i < n; i++) {
		cin >> x;
		x--;
		nxt[0][i] = x;
	}

	for(int j = 1; j < l; j++)
		for(int i = 0; i < n; i++)
			nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];

	while(q--) {
		cin >> x >> k;
		x--;
		for(int j = l - 1; j >= 0; j--) {
			if(k >= (1 << j)) {
				x = nxt[j][x];
				k -= (1 << j);
			}
		}
		cout << x + 1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	#ifndef DUSH1729
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);

	int t = 1;
	if(areTests) cin >> t;
	for(int i = 1; i <= t; i++) {
		run_test(i);
	}
}