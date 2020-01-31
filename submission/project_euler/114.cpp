#include "bits/stdc++.h"
using namespace std;

int n;

int main()
{
	cin>>n;

	vector <vector <int>> dp(n+1,vector <int> (2,1));
	for(int i=0;i<=n;i++) dp[i][1]=0;

	for(int i=3;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			dp[j][1]+=dp[j-i][0];
			for(int k=j+1;k<=n;k++) dp[k][0]+=dp[j][1];
		}
	}

	cout<<dp[n][0]+dp[n][1]
}