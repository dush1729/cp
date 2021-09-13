#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 1;



void run_test(int testcase) {
	int n;
	string a;
	cin >> n >> a;

	int switch_hands = 0;
	char previous = '$';
	for(char &c: a) {
		if(c == 'X') {
			if(previous == 'O') switch_hands++;
			previous = c;
		} else if(c == 'O') {
			if(previous == 'X') switch_hands++;
			previous = c;
		}
	}

	cout << "Case #" << testcase << ": " << switch_hands << "\n";
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