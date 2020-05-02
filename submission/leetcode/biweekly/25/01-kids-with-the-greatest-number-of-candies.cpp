#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
	vector<bool> kidsWithCandies(vector<int>& a, int x)
	{
		int mx=*max_element(a.begin(),a.end());
		vector <bool> ans;
		for(auto i:a)
		{
			if(i+x>=mx) ans.push_back(true);
			else ans.push_back(false);
		}
		return ans;
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif