#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int areTests = 0;

int sz;

struct query {
	int l, r, i;
	bool operator<(const query &T) const {
		if (l / sz != T.l / sz) return l < T.l;
		return (l / sz) & 1 ? r < T.r : r > T.r;
	}
};

void run_test(int testcase) {
	int n, q, mx = 0;
	cin >> n >> q;
	sz = sqrt(n);
	vector a(n, 0);
	for(int &x: a) cin >> x;

	auto s = a;
	sort(s.begin(), s.end());
	for(int &x: a) {
		x = lower_bound(s.begin(), s.end(), x) - s.begin() + 1;
		mx = max(mx, x);
	}

	vector <query> p(q);
	for(int i = 0; i < q; i++) {
		cin >> p[i].l >> p[i].r;
		p[i].l--, p[i].r--;
		p[i].i = i;
	}

	int cl = 0, cr = -1, cnt = 0;
	vector <int> f(mx + 1);
	auto add = [&](int i) {
		i = a[i];
		if(f[i] == 0) cnt++;
		f[i]++;
	};
	auto remove = [&](int i) {
		i = a[i];
		f[i]--;
		if(f[i] == 0) cnt--;
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
	for(int &x: ans) cout << x << "\n";
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