#include "bits/stdc++.h"
using namespace std;

const int N=2e3+20;

int t,dp[N][N];
string a,b;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int n=a.size(),m=b.size();
		a="$"+a,b="$"+b;
	
		for(int j=1;j<=m;j++) dp[0][j]=j;
		for(int i=1;i<=n;i++) dp[i][0]=i;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
				else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
			}
		}
	
		cout<<dp[n][m]<<"\n";
	}
}