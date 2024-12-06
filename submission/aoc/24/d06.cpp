#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, N = 130;

int ans, vis[N][N];
string a[N];
vector <pair <int, int>> dirs = {{-1, 0}, { 0,+1}, {+1, 0}, { 0,-1}};

bool in(int x, int y) {return min(x, y) >= 0 && max(x, y) < N;}

void go(int x, int y, int d) {
	if(!vis[x][y]) ans++;
	vis[x][y] = 1;

	const auto &[dx, dy] = dirs[d];
	int nx = x + dx, ny = y + dy;
	if(in(nx, ny)) {
		if(a[nx][ny] == '#') {
			nx = x, ny = y;
			d = (d + 1) % 4;
		}
		go(nx, ny, d);
	}
}


void run_test(int testcase) {
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(a[i][j] == '^') go(i, j, 0);
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