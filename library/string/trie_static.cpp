/*
Problems
https://binarysearch.com/problems/Trie
https://codeforces.com/contest/665/problem/E
https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3
*/

const int BASE = 26, SZ = 1e6 + 2, START = 'a';

int pos, nxt[SZ][BASE];
//unordered_map <int, unordered_map <int, int>> nxt;
struct node {
	int count;
	bool end;
	node(): count(0), end(false) {}
};
node nodes[SZ];

struct TRIE {
	TRIE() {
		for(int i = 1; i <= pos; i++) {
			nodes[i] = node();
		}
		memset(nxt, 0, pos * sizeof(nxt[0]));
		//nxt.clear();
		pos = 1;
	}

	void add(string s) {
		int u = 0;
		for(auto &c: s) {
			nodes[u].count++;
			if(!nxt[u][c - START]) nxt[u][c - START] = pos++;
			u = nxt[u][c - START];
		}		
		nodes[u].count++;
		nodes[u].end = true;
	}

	bool exists(string s, bool prefix = false) {
		int u = 0;
		for(auto &c: s) {
			if(!nxt[u][c - START]) return false;
			u = nxt[u][c - START];
		}
		return prefix or nodes[u].end;
	}

	bool startswith(string s) {
		return exists(s, true);
	}
};