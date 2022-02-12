/*
Problems
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
		node* nxt[BASE] = {};
	};
	node* head = new node();

	void add(const string &s) {
		auto ptr = head;
		for(const char &c: s) {
			ptr->count++;
			if(!ptr->nxt[c - START]) ptr->nxt[c - START] = new node();
			ptr = ptr->nxt[c - START];
		}
		ptr->count++;
		ptr->end = true;
	}

	node* del(const string &s, node *ptr, int i = 0) {
		if(i < s.size()) {
			ptr->nxt[s[i] - START] = del(s, ptr->nxt[s[i] - START], i + 1);
		}

		ptr->count--;
		if(ptr->count == 0) {
			ptr->end = false;
			return nullptr;
		} else {
			return ptr;
		}
	}

	bool exists(const string &s, bool prefix = false) {
		auto ptr = head;
		for(const char &c: s) {
			if(!ptr->nxt[c - START]) return false;
			ptr = ptr->nxt[c - START];
		}
		return prefix or ptr->end;
	}

	bool startswith(const string &s) {
		return exists(s, true);
	}
};