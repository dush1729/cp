#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0, N = 140;



void run_test(int testcase) {
	vector <string> a(N);
	for(int i = 0; i < N; i++) cin >> a[i];

	auto in = [&](int i, int j) {
		return i >= 0 && j >= 0 && i < N && j < a[i].size();
	};

	auto ok = [&](vector <pair <int, int>> points) {
		for(auto &[x, y]: points) {
			for(int dx = -1; dx <= 1; dx++) {
				for(int dy = -1; dy <= 1; dy++) {
					int nx = x + dx, ny = y + dy;
					if(in(nx, ny) && a[nx][ny] != '.' && !isdigit(a[nx][ny])) return true;
				}
			}
		}
		return false;
	};

	ll ans = 0;
	for(int i = 0; i < N; i++) {
		int m = a[i].size();
		for(int j = 0; j < m; ) {
			for( ; j < m && !isdigit(a[i][j]); j++) ;
			if(j >= m) break;

			vector <pair <int, int>> points;
			string num;
			for( ; j < m && isdigit(a[i][j]); j++) {
				points.push_back({i, j});
				num += a[i][j];
			}

			if(!num.empty() && ok(points)) ans += stoll(num);
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