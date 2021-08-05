#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define vvi vector <vector <int>>
const int areTests = 0;

const int MOD = 1e9 + 7;

int add(int x, int y) {return (0ll + x + y) % MOD;}
int mul(int x, int y) {return (1ll * x * y) % MOD;}

vvi mul(vvi &a, vvi &b) {
	int n1 = a.size(), m1 = a[0].size();
	int n2 = b.size(), m2 = b[0].size();
	assert(m1 == n2);
	vvi ans=vvi(n1, vector <int> (m2, 0));
	for(int i = 0; i < n1; i++)
		for(int j = 0; j < m2; j++)
			for(int k = 0; k < n2; k++)
				ans[i][j] = add(ans[i][j], mul(a[i][k], b[k][j]));
	return ans;
}

void run_test(int testcase) {
	ll n, k;
	cin >> n >> k;
	vector a(n, vector (n, 0));
	for(auto &v: a)
		for(int &x: v) cin >> x;

	vvi ans(1, vector (n, 1));
	while(k) {
		if(k & 1) ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}

	ll s = 0;
	for(int &x: ans[0]) s = add(s, x);
	cout << s;
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