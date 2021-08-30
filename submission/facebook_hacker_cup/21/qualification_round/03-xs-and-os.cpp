#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 1;

void transpose(vector <string> &a) {
	auto b = a;
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < a.size(); j++)
			b[j][i] = a[i][j];
	a = b;
}

void run_test(int testcase) {
	int n;
	cin >> n;
	vector <string> a(n);
	for(string &s: a) cin >> s;

	int min_moves = INT_MAX, ways;
	for(int it = 0; it < 2; it++) {
		for(int i = 0; i < n; i++) {
			int moves = n, ok = 1;
			for(int j = 0; j < n; j++) {
				if(a[i][j] == 'O') ok = 0;
				else if(a[i][j] == 'X') moves--;
			}

			if(!ok) continue;
			if(min_moves > moves) {
				min_moves = moves;
				ways = 1;
			} else if(min_moves == moves) {
				ways++;
			}
		}

		transpose(a);
	}

	cout << "Case #" << testcase << ": ";
	if(min_moves == INT_MAX) {
		cout << "Impossible\n";
		return;
	} else if(min_moves == 1) {
		// recalculate ways
		ways = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(a[i][j] != '.') continue;
				int okrow = 1, okcol = 1;
				for(int r = 0; r < n && okrow; r++) {
					if(r != i && a[r][j] != 'X') okrow = 0;
				}
				for(int c = 0; c < n && okcol; c++) {
					if(c != j && a[i][c] != 'X') okcol = 0;
				}
				if(okrow || okcol) ways++;
			}
		}
	}
	cout << min_moves << " " << ways << "\n";
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