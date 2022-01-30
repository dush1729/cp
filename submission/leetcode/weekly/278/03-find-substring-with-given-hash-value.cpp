#define ll long long
class Solution {
public:
	string subStrHash(string haystack, int BASE, int MOD, int k, int hash) {
		reverse(haystack.begin(), haystack.end());

		ll p = 1;
		for(int i = 0; i < k; i++) {
			if(i + 1 != k) p = (p * BASE) % MOD;
		}

		int idx = -1;
		for(ll x = 0, i = 0; i < haystack.size(); i++) {
			if(i >= k) x -= (p * (haystack[i - k] - 'a' + 1)) % MOD;
			x %= MOD;
			if(x < 0) x += MOD;
			x = (x * BASE + haystack[i] - 'a' + 1) % MOD;
			if(i >= k - 1 && x == hash) idx = i - k + 1;
		}

		assert(idx != -1);
		string ans = haystack.substr(idx, k);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};