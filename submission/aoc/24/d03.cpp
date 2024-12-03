#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int areTests = 0;

ll process(const string &a) {
	ll n = a.size(), ans = 0;
	for(int i = 2; i < n; i++) {
		if(a[i - 2] == 'm' && a[i - 1] == 'u' && a[i] == 'l') {
			i++;
			if(i < n && a[i] != '(') continue;
			i++;

			string x;
			for(; i < n && isdigit(a[i]); i++) x += a[i];
			if(x.empty() || x.size() > 3) continue;

			if(i < n && a[i] != ',') continue;
			i++;

			string y;
			for(; i < n && isdigit(a[i]); i++) y += a[i];
			if(y.empty() || y.size() > 3) continue;

			if(i < n && a[i] != ')') continue;

			ans += stoi(x) * stoi(y);
		}
	}
	return ans;
}

void run_test(int testcase) {
	string a;
	ll ans = 0;
	while(getline(cin, a)) {
		ans += process(a);
	}
	cout << ans;
}

int main() {
	int t = 1;
	if(areTests) cin >> t;
	for(int i = 1; i <= t; i++) {
		run_test(i);
	}
}