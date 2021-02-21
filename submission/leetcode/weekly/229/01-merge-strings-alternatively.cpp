#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
	string mergeAlternately(string a, string b)  {
		string ans;
		int n = a.size(), m = b.size();
		for(int i = 0, j = 0; i < n or j < m;) {
			if(i < n) ans += a[i++];
			if(j < m) ans += b[j++];
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
