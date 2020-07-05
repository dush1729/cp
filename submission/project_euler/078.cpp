#include "bits/stdc++.h"
using namespace std;

const int N=6e4,MOD=1e6;

int dp[N];

int main()
{
	dp[0]=1;

	for(int i=1;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			dp[j]+=dp[j-i];
			dp[j]%=MOD;
		}
		if(dp[i]==0) return 0 * printf("%d ",i);
	}
}