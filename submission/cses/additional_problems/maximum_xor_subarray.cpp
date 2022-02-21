#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0, B = 30;

const int BASE = 2;

struct TRIE {
	struct node {
		int count = 0;
		bool end = false;
	};

	int pos = 1;
	vector <array <int, BASE>> nxt;
	vector <node> nodes;

	void add(const int &x) {
		int u = 0;
		for(int bit = B - 1; bit >= 0; bit--) {
			if(u >= nodes.size()) nodes.resize(u + 1);
			nodes[u].count++;
			if(u >= nxt.size()) nxt.resize(u + 1);
			int c = bool(x & (1 << bit));
			if(!nxt[u][c]) nxt[u][c] = pos++;
			u = nxt[u][c];
		}
		if(u >= nxt.size()) nxt.resize(u + 1);
		if(u >= nodes.size()) nodes.resize(u + 1);
		nodes[u].count++;
		nodes[u].end = true;
	}

	int get(const int &x) {
		int u = 0, ans = 0;
		for(int bit = B - 1; bit >= 0; bit--) {
			int c = bool(x & (1 << bit));
			if(nxt[u][c ^ 1]) {
				c ^= 1;
				ans += 1 << bit;
			}
			u = nxt[u][c];
		}
		return ans;
	}
};

void run_test(int testcase) {
	int n, x, xr = 0, ans = 0;
	cin >> n;

	auto trie = TRIE();
	trie.add(0);
	while(n--) {
		cin >> x;
		xr ^= x;
		ans = max(ans, trie.get(xr));
		trie.add(xr);
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