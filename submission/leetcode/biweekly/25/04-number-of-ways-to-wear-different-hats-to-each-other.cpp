#include "bits/stdc++.h"
using namespace std;

const int N=12,M=50,MOD=1e9+7;

int v[M],dp[M][1<<N];

class Solution
{
public:
	int numberWays(vector<vector<int>>& a)
	{
		int n=a.size();
		for(int i=0;i<M;i++) v[i]=0;
		for(int i=0;i<n;i++)
			for(auto j:a[i]) v[j]^=(1<<i);

		for(int i=0;i<M;i++)
			for(int j=0;j<(1<<N);j++) dp[i][j]=0;

		dp[0][0]=1;
		for(int i=1;i<M;i++)
		{
			for(int j=0;j<(1<<n);j++) dp[i][j]=dp[i-1][j];
			for(int mask=0;mask<(1<<n);mask++)
			{
				for(int j=0;j<n;j++)
				{
					if(!(mask&(1<<j)) or !(v[i]&(1<<j))) continue;
					dp[i][mask]+=dp[i-1][mask^(1<<j)];
					dp[i][mask]%=MOD;
				}
			}
		}
		return dp[M-1][(1<<n)-1];
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=Solution().maxSumDivThree(v);
}
#endif