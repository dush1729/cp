#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, n = 140;

string s = "XMAS";
int ans;
string a[n];
vector <pair <int, int>> dirs = {
	{+1, 0},
	{-1, 0},
	{ 0,+1},
	{ 0,-1},
	{+1,-1},
	{+1,+1},
	{-1,-1},
	{-1,+1},
};

bool in(int x,int y) {
	return min(x, y) >= 0 && max(x, y) < n;
}

void go(int x, int y, int d, int i) {
	if(i == s.size()) {
		ans++;
		return ;
	}
	if(!in(x, y) || a[x][y] != s[i]) return ;
	int nx = x + dirs[d].first, ny = y + dirs[d].second;
	go(nx, ny, d, i + 1);
}

void run_test(int testcase) {
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int d = 0; d < 8; d++) {
				go(i, j, d, 0);
			}
		}
	}
	cout << ans;
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