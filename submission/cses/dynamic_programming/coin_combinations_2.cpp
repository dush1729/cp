#include "bits/stdc++.h"
using namespace std;

const int MOD=1e9+7;

int n,s,x;

int main()
{
	cin>>n>>s;
	vector <int> dp(s+1,0);
	dp[0]=1;

	while(n--)
	{
		cin>>x;
		for(int i=x;i<=s;i++) dp[i]=(dp[i]+dp[i-x])%MOD;
	}

	cout<<dp.back();
}