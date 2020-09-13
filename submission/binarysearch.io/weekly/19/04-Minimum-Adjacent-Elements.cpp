#include "solution.hpp"
using namespace std;


class Solution {
	public:
	int solve(vector<int>& nums) {
		int n=nums.size();
		map <int,vector <int>> m;
		for(int i=0;i<n;i++)
			m[nums[i]].push_back(i);

		int ans=INT_MAX;
		vector <vector <int>> v;
		for(auto p:m)
		{
			v.push_back(p.second);

			for(int i=1;i<v.back().size();i++)
				ans=min(ans,v.back()[i]-v.back()[i-1]);
		}

		for(int i=0;i+1<v.size();i++)
		{
			vector <pair <int,int>> nlist;

			vector <int> v1=v[i],v2=v[i+1];
			v1.push_back(INT_MAX),v2.push_back(INT_MAX);
			reverse(v1.begin(),v1.end()),reverse(v2.begin(),v2.end());

			while(v1.back()!=INT_MAX or v2.back()!=INT_MAX)
			{
				if(v1.back()<v2.back())
				{
					nlist.push_back({v1.back(),0});
					v1.pop_back();
				}
				else
				{
					nlist.push_back({v2.back(),1});
					v2.pop_back();
				}
			}

			for(int i=1;i<nlist.size();i++)
				if(nlist[i].second!=nlist[i-1].second) ans=min(ans,nlist[i].first-nlist[i-1].first);
		}

		return ans;
	}
};