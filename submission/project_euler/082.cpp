#include "bits/stdc++.h"
using namespace std;
const int N=80;
int a[N][N],dp[N][N],ans=INT_MAX;
int main()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>a[i][j];

	for(int i=0;i<N;i++) dp[i][0]=a[i][0];
	for(int j=1;j<N;j++)
	{
		for(int i=0;i<N;i++) dp[i][j]=dp[i][j-1]+a[i][j];
		for(int i=1;i<N;i++) dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i][j]);
		for(int i=N-2;i>=0;i--) dp[i][j]=min(dp[i][j],dp[i+1][j]+a[i][j]);
	}

	for(int i=0;i<N;i++) ans=min(ans,dp[i][N-1]);
	printf("%d",ans);
}