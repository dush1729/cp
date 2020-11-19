#include "bits/stdc++.h"
using namespace std;

const int N=1e6+20,MOD=1e9+7;

int n,dp[N];

int main()
{
	scanf("%d",&n);
	dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=min(i,6);j++)
			dp[i]=(dp[i]+dp[i-j])%MOD;
	printf("%d",dp[n]);
}