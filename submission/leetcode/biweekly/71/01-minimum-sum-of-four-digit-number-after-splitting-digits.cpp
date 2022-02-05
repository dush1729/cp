class Solution {
public:
	int minimumSum(int num) {
		string s = to_string(num);
		sort(s.begin(), s.end());
		int ans = INT_MAX;

		do {
			for(int mask = 0; mask < (1 << 4); mask++) {
				string a = "0", b = "0";
				for(int i = 0; i < 4; i++) {
					if(mask & (1 << i)) a += s[i];
					else b += s[i];
				}
				ans = min(ans, stoi(a) + stoi(b));
			}
		} while(next_permutation(s.begin(), s.end()));
		return ans;
	}
};