#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0, MOD = 1e9 + 7;

const int BASE = 26, START = 'a';

struct TRIE {
	struct node {
		int count = 0;
		bool end = false;
	};

	int pos = 1, tu;
	vector <array <int, BASE>> nxt;
	vector <node> nodes;

	void add(const string &s) {
		int u = 0;
		for(auto &c: s) {
			if(u >= nodes.size()) nodes.resize(u + 1);
			nodes[u].count++;
			if(u >= nxt.size()) nxt.resize(u + 1);
			if(!nxt[u][c - START]) nxt[u][c - START] = pos++;
			u = nxt[u][c - START];
		}
		if(u >= nxt.size()) nxt.resize(u + 1);
		if(u >= nodes.size()) nodes.resize(u + 1);
		nodes[u].count++;
		nodes[u].end = true;
	}

	bool exists(const char &c) {
		if(!nxt[tu][c - START]) return false;
		tu = nxt[tu][c - START];
		return true;
	}
};

void run_test(int testcase) {
	string a;
	cin >> a;
	int m;
	cin >> m;
	auto trie = TRIE();
	while(m--) {
		string s;
		cin >> s;
		trie.add(s);
	}

	int n = a.size();
	vector dp(n + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		trie.tu = 0;
		for(int j = i; j <= n; j++) {
			if(!trie.exists(a[j - 1])) break;
			if(trie.nodes[trie.tu].end) dp[j] = (dp[j] + dp[i - 1]) % MOD;
		}
	}
	cout << dp[n];
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