#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
	bool f(string a) {
		sort(a.begin(), a.end());
		for(char c: a) {
			char r1 = toupper(c);
			char r2 = tolower(c);
			if(!binary_search(a.begin(), a.end(), r1)) return false;
			if(!binary_search(a.begin(), a.end(), r2)) return false;
		}
		return true;
	}

	string longestNiceSubstring(string s) {
		int n = s.size();
		string ans;
		for(int i = 0; i < n; i++) {
			string a;
			for(int j = i; j < n; j++) {
				a += s[j];
				if(f(a) && ans.size() < a.size()) ans = a;
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
