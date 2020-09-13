#include "solution.hpp"
using namespace std;

const int N=1e5+20,L=25;

int n,a[N],lg[N];
long long dp[N];
int st[N][L]; 

void build()
{
	for(int i=2;i<N;i++) lg[i]=lg[i>>1]+1;
	for(int j=0;j<L;j++)
	{
		for(int i=1;i+(1<<j)<=n+1;i++)
		{
			if(j==0) st[i][0]=a[i];
			else st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}

// O(lgn) query for associative functions
int query(int l,int r)
{
	int s=INT_MIN;
	for(int j=L-1;j>=0;j--)
	{
		if((1<<j)>r-l+1) continue;
		s=max(s,st[l][j]);
		l+=1<<j;
	}
	return s;
}

// O(1) query for idempotent functions
int queryf(int l,int r)
{
	int j=lg[r-l+1];
	return max(st[l][j],st[r-(1<<j)+1][j]);
}

class Solution {
	public:
	int solve(vector<int>& nums, int k) {
		if(nums.empty()) return 0;
		n=nums.size();
		for(int i=1;i<=n;i++)
		{
			a[i]=nums[i-1];
			dp[i]=dp[i-1]+a[i];
		}
		build();

		int ans=1;
		for(int i=1;i<=n;i++)
		{
			int lo=i,hi=n,idx=-1;
			while(lo<=hi)
			{
				int mid=(lo+hi)/2;
				int mx=queryf(i,mid);

				long long moves=1ll*mx*(mid-i+1)-(dp[mid]-dp[i-1]);
				if(moves<=k) idx=mid,lo=mid+1;
				else hi=mid-1;
			}
			ans=max(ans,idx-i+1);
		}
		return ans;
	}
};
