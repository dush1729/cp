#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;

vector <char> vec = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};

int rnk(string a) {
	map <int, int> m;
	for(auto &c: a) m[c]++;
	vector <int> f;
	for(auto &[x, freq]: m) f.push_back(freq);
	sort(f.begin(), f.end());

	if(f.size() == 1) return 1 << 7;
	if(f.size() == 2 && f.back() == 4) return 1 << 6;
	if(f.size() == 2 && f.back() == 3 && f[0] == 2) return 1 << 5;
	if(f.back() == 3) return 1 << 4;
	if(f.size() == 3 && f[0] == 1 && f[1] == 2 && f[2] == 2) return 1 << 3;	
	if(f.back() == 2) return 1 << 2;
	return 1 << 1;
}

int rnk2(char c) {
	for(int i = 0; i < vec.size(); i++)
		if(vec[i] == c) return i;
	assert(false);
	return 100;
}

void run_test(int testcase) {
	vector <pair <string, ll>> a;
	for(int hands = 0; hands < 1000; hands++) {
		string s;
		getline(cin, s);
		
		string hand;
		int i = 0;
		while(s[i] != ' ') hand += s[i], i++;
		i++;

		ll val = 0;
		while(i < s.size()) val = val * 10 + s[i] - '0', i++;

		a.push_back({hand, val});
	}

	sort(a.begin(), a.end(), [](const auto &p, const auto &q) {
		ll rp = rnk(p.first), rq = rnk(q.first);
		if(rp != rq) return rp < rq;

		for(int i = 0; i < p.first.size(); i++) {
			if(p.first[i] != q.first[i]) return rnk2(p.first[i]) > rnk2(q.first[i]);
		}
		assert(false);
		return false;
	});

	ll ans = 0;
	for(int i = 0; i < a.size(); i++) {
		//cout << a[i].first << " " << i + 1 << endl;
		ans += (i + 1) * a[i].second;
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