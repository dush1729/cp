#include "solution.hpp"
using namespace std;

const int N=1000;

long long dp[N][N];

class Solution {
	public:
	int solve(int n, int k) {
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(i>1) dp[i][j]+=dp[i-2][j];
				if(i>2 and j>0) dp[i][j]+=dp[i-3][j-1];
			}
		}

		long long ans=0;
		for(int j=0;j<=k;j++) ans+=dp[n][j];

		return ans;
	}
};
