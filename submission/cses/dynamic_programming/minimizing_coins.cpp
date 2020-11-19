#include "bits/stdc++.h"
using namespace std;

const int MAX=1e8;

int n,s,x;

int main()
{
	scanf("%d%d",&n,&s);

	vector <int> dp(s+1,MAX);
	dp[0]=0;
	while(n--)
	{
		scanf("%d",&x);
		for(int i=x;i<=s;i++) dp[i]=min(dp[i],dp[i-x]+1);
	}
	if(dp[s]==MAX) dp[s]=-1;
	printf("%d",dp[s]);
}