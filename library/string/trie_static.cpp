/*
Problems
https://leetcode.com/problems/word-break/description/
https://binarysearch.com/problems/Trie
https://codeforces.com/contest/665/problem/E
https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3
https://codeforces.com/contest/706/problem/D
*/

const int BASE = 26, START = 'a';

struct TRIE {
	struct node {
		int count = 0;
		bool end = false;
	};

	int pos = 1, p;
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

	bool exists(const string &s, bool prefix = false) {
		int u = 0;
		for(auto &c: s) {
			if(!nxt[u][c - START]) return false;
			u = nxt[u][c - START];
		}
		return prefix or nodes[u].end;
	}

	bool exists(const char &c, bool init_ptr = false) {
		if(init_ptr) p = 0;
		if(!nxt[p][c - START]) return false;
		p = nxt[p][c - START];
		return true;
	}

	bool startswith(const string &s) {
		return exists(s, true);
	}

	TRIE() {}
	TRIE(const vector <string> &a) {
		for(auto &s: a) add(s);
	}
};