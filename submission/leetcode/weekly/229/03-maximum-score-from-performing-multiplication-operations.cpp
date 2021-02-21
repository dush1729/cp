#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 1e3 + 20;
const ll MIN = -1e18;

ll dp[N][N], cache[N][N];

class Solution {
public:
	int n, m;
	vector <int> a, mul;

	ll f(int l, int r) {
		int del = l + n - 1 - r;
		if(del >= m) return 0;
		if(cache[l][del]) return dp[l][del];

		cache[l][del] = 1;
		dp[l][del] = max(f(l + 1, r) + 1ll * a[l] * mul[del],
			f(l, r - 1) + 1ll * mul[del] * a[r]);
		return dp[l][del];
	}


	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		n = nums.size(), m = multipliers.size();
		a = nums, mul = multipliers;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				cache[i][j] = 0;
				dp[i][j] = MIN;
			}
		}

		return f(0, n - 1);
	}
};

#ifdef LOCAL
int main() {
	vector <int> v = {1, 2};
	auto ans = Solution().maxSumDivThree(v);
}
#endif
