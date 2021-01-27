/*
Problems
https://codeforces.com/gym/102644/problem/C
*/
#include "bits/stdc++.h"
using namespace std;
#define vvi vector <vector <int>>

const int MOD = 1e9 + 7;

long long n;

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

vvi f(long long n) {
	vvi ans = {{0, 1}};
	vvi p = {{0, 1}, {1, 1}};
	while(n) {
		if(n & 1) ans = mul(ans, p);
		p = mul(p, p);
		n >>= 1;
	}
	return ans;
}

int main() {
	cin >> n;
	cout << f(n)[0][0];
}