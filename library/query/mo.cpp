/*
Problems
https://atcoder.jp/contests/abc238/tasks/abc238_g
https://codeforces.com/problemset/problem/86/D
*/

int sz;

struct query {
	int l, r, i;
	bool operator<(const query &T) const {
		if (l / sz != T.l / sz) return l < T.l;
		return (l / sz) & 1 ? r < T.r : r > T.r;
	}
};

int main() {
	//read n, prefer local over global variables(see abc238g submissions)
	sz = sqrt(n);

	vector <query> p(q);
	for(int i = 0; i < q; i++) {
		cin >> p[i].l >> p[i].r;
		p[i].l--, p[i].r--;
		p[i].i = i;
	}

	int cl = 0, cr = -1, cnt = 0;
	auto add = [&](int i) {
	};
	auto remove = [&](int i) {
	};

	sort(p.begin(), p.end());
	vector <int> ans(q);
	for(auto &[l, r, idx]: p) {
		while(cl > l) add(--cl);
		while(cr < r) add(++cr);
		while(cl < l) remove(cl++);
		while(cr > r) remove(cr--);
		ans[idx] = cnt;
	}
}