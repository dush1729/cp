class Solution {
public:
	int sumOfFlooredPairs(vector<int>& a) {
		int mx = 2e5;
		vector <int> f(mx + 1), dp(mx + 1);
		for(int x: a) f[x]++;
		for(int i = 1; i <= mx; i++) dp[i] = dp[i - 1] + f[i];

		ll ans = 0;
		for(int i = 1; i <= mx; i++) {
			if(dp[i] - dp[i - 1] == 0) continue;
			int j = 2 * i;
			for( ; j <= mx; j += i) {
				ll p = (1ll * (dp[j - 1] - dp[j - i - 1]) * (j / i - 1)) % MOD;
				p *= (dp[i] - dp[i - 1]);
				p %= MOD;

				ans += p;
				ans %= MOD;
			}
		}
		return ans;
	}
};