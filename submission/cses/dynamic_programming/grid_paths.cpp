#include "bits/stdc++.h"
using namespace std;

const int N=1e3+20,MOD=1e9+7;

int n,dp[N][N];
char a[N][N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf(" %s",a[i]+1);

	if(a[1][1]=='.') dp[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==1 and j==1) continue;
			if(a[i][j]=='*') continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
			dp[i][j]%=MOD;
		}
	}
	printf("%d",dp[n][n]);
}