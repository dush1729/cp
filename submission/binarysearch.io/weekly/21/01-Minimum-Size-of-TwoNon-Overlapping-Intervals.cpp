#include "solution.hpp"
using namespace std;


class Solution {
	public:
	
	int solve(vector<vector<int>>& intervals) {
		vector <pair <int,int>> v;
		for(auto vec:intervals) v.push_back({vec[0],vec[1]});
		
		sort(v.begin(),v.end());
		vector <int> dp;
		int mn=INT_MAX;
		for(int i=v.size()-1;i>=0;i--)
		{
			mn=min(mn,v[i].second-v[i].first+1);
			dp.push_back(mn);
		}
		reverse(dp.begin(),dp.end());



		int ans=INT_MAX;
		for(auto p:v)
		{
			auto idx=lower_bound(v.begin(),v.end(),make_pair(p.second+1,0))-v.begin();
			if(idx!=v.size())
			{
				ans=min(ans,p.second-p.first+dp[idx]+1);
			}
		}
		if(ans==INT_MAX) ans=0;
		return ans;
	}
};
