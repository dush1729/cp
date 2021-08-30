#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 1, C = 26, MAX = 1e9;



void run_test(int testcase) {
	string a;
	cin >> a;

	vector adj(C, vector (C, 0));
	int m;
	cin >> m;
	while(m--) {
		string s;
		cin >> s;
		adj[s[1] - 'A'][s[0] - 'A'] = 1;
	}

	vector dp(C, vector (C, MAX));
	for(int c = 0; c < C; c++) {
		vector dist(C, MAX);
		queue <int> q;

		auto add = [&](int node, int d) {
			q.push(node);
			dist[node] = d;
		};

		add(c, 0);
		while(!q.empty()) {
			int node = q.front();
			q.pop();
			for(int child = 0; child < C; child++) {
				if(adj[node][child] && dist[child] == MAX) {
					add(child, dist[node] + 1);
				}
			}
		}

		dp[c] = dist;
	}

	vector frequency(C, 0);
	for(char &c: a) {
		frequency[c - 'A']++;
	}
	int ans = MAX;
	for(int c = 0; c < C; c++) {
		int moves = 0, ok = 1;
		for(int d = 0; d < C; d++) {
			if(d == c || frequency[d] == 0) continue;
			if(dp[c][d] == MAX) ok = 0;
			else moves += dp[c][d] * frequency[d];
		}
		if(ok) ans = min(ans, moves);
	}
	if(ans == MAX) ans = -1;
	cout << "Case #" << testcase << ": ";
	cout << ans << "\n";
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