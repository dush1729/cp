#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
	vector<int> minOperations(string a) {
		vector <int> ans;
		int n = a.size();

		for(int i = 0; i < n; i++) {
			int s = 0;
			for(int j = 0; j < n; j++) {
				if(a[j] == '1') s += abs(i - j);
			}
			ans.push_back(s);
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
