#include "bits/stdc++.h"
using namespace std;
 
const int N = 5e3 + 20;
 
#define ll long long
 
int n, a[N];
ll dp[N][N];
bool calc[N][N];
 
ll f(int l, int r) {
	if(calc[l][r]) return dp[l][r];
	calc[l][r] = true;
 
	int player = (n - (r - l + 1)) % 2;
	ll &ans = dp[l][r];
	if(r - l <= 1) {
		if(player) ans = min(a[l], a[r]);
		else ans = max(a[l], a[r]);
	} else if(player) {
		ans = min(f(l + 1, r), f(l, r - 1));
	} else {
		ans = max(a[l] + f(l + 1, r), a[r] + f(l, r - 1));
	}
	return ans;
}
 
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%lld", f(0, n - 1));
}