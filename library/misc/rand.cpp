#include "bits/stdc++.h"
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cout << rng() << endl; // to generate random number
}