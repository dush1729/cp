#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20,M=1e2+20,MOD=1e9+7;

int n,m,a[N],dp[N][M];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	if(a[0]) dp[0][a[0]]=1;
	else
	{
		for(int j=1;j<=m;j++) dp[0][j]=1;
	}

	for(int i=0;i<n;i++)
	{
		int x=a[i];
		if(x)
		{
			dp[i][x]=(dp[i-1][x-1]+dp[i-1][x])%MOD;
			dp[i][x]=(dp[i][x]+dp[i-1][x+1])%MOD;
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
				dp[i][j]=(dp[i][j]+dp[i-1][j+1])%MOD;
			}
		}
	}

	int ans=0;
	for(int j=1;j<=m;j++) ans=(ans+dp[n-1][j])%MOD;
	printf("%d",ans);
}