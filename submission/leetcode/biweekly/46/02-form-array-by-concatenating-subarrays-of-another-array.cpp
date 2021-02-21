#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
	bool canChoose(vector<vector<int>>& groups, vector<int>& a) {
		int i = 0;
		for(const auto &v: groups) {
			int f = 0;
			for(int j = i; j <= (int)a.size() - (int)v.size(); j++) {
				vector <int> vec;
				for(int k = j; k < j + v.size(); k++) {
					vec.push_back(a[k]);
				}
				if(vec == v) {
					i = j + v.size();
					f = 1;
					break;
				}
				
			}
			if(f == 0) return false;
		}
		return i <= a.size();
	}
};

#ifdef LOCAL
int main() {
	vector <int> v = {1, 2};
	auto ans = Solution().maxSumDivThree(v);
}
#endif
