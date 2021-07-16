#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 0;

int f(string a) {
	bool caps = false, under = false;
	for(char &c: a) {
		if(isupper(c)) caps = true;
		if(c == '_') under = true;
	}
	if(caps && under) return -1;
	if(!caps && !under) return 0;
	if(caps) return isupper(a[0]) ? -1 : 1;
	for(int i = 1; i < a.size(); i++)
		if(a[i] == '_' && a[i - 1] == '_') return -1;
	return a[0] == '_' || a.back() == '_' ? -1 : 2;
}

void run_test(int testcase) {
	string a;
	while(cin >> a) {
		int status = f(a);

		string ans;
		if(status == -1) ans = "Error!";
		else if(status == 0) ans = a;
		else if(status == 1) {
			for(char &c: a) {
				if(isupper(c)) {
					ans += "_";
					ans += c - 'A' + 'a';
				} else {
					ans += c;
				}
			}
		} else {
			bool caps = false;
			for(char &c: a) {
				if(c == '_') {
					caps = true;
				} else {
					if(caps) ans += c - 'a' + 'A';
					else ans += c;
					caps = false;
				}
			}
		}
		cout << ans << "\n";
	}
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