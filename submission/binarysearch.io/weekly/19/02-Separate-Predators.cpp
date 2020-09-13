#include "solution.hpp"
using namespace std;

const int N=2e5+20;

vector <int> adj[N];
int ans,dp[N];

void dfs(int node)
{
	dp[node]=1;
	for(auto child:adj[node])
	{
		if(dp[child]==-1) dfs(child);
		dp[node]=max(dp[node],dp[child]+1);
	}
	ans=max(ans,dp[node]);
}

class Solution {
	public:
	int solve(vector<int>& nums) {
		int n=nums.size();
		ans=0;
		for(int i=0;i<n;i++)
		{
			adj[i].clear();
			dp[i]=-1;
		}

		for(int i=0;i<n;i++)
			if(nums[i]!=-1) adj[i].push_back(nums[i]);

		for(int i=0;i<n;i++)
			if(dp[i]==-1) dfs(i);
		return ans;
	}
};
