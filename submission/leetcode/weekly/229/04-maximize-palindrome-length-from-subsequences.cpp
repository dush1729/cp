#include "bits/stdc++.h"
using namespace std;

const int N = 2e3 + 20;

class Solution {
public:
	int dp[N][N];


	void lps(string a) {
		int n = a.size();
		for(int l = n - 1;  l > 0; l--) {
			for(int r = l; r < n; r++) {
				if(r == l) dp[l][r] = 1;
				else if(r - l == 1) {
					if(a[l] == a[r]) dp[l][r] = 2;
					else dp[l][r] = 1;
				}
				else {
					if(a[l] == a[r]) dp[l][r] = 2 + dp[l + 1][r - 1];
					else dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
				}
			}
		}
	}


	int longestPalindrome(string a, string b) {
		int n = a.size(), m = b.size(), ans = 0;

		string s = a + b;
		lps(s);

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i] == b[j]) {
					ans = max(ans, 2 + dp[i + 1][n + j - 1]);
				}
			}
		}

		return ans;
	}
};

#ifdef LOCAL
int main() {
	vector <int> v = {1, 2};
	auto ans = Solution().maxSumDivThree(v);
}
#endif
