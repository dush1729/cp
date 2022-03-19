class Solution {
public:
	long long f(string a, string p) {
		long long r = count(a.begin(), a.end(), p[1]), ans = 0;

		if(p[0] == p[1]) {
			return r * (r - 1) / 2;
		}

		for(char &c: a) {
			if(c == p[0]) {
				ans += r;
			}
			else if(c == p[1]) {
				r--;
			}
		}
		return ans;
	}

	long long maximumSubsequenceCount(string a, string p) {
		return max(f(p[0] + a, p), f(a + p[1], p));
	}
};