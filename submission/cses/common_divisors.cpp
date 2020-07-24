#include "bits/stdc++.h"
using namespace std;

const int N=1e6+20;

int n,x,dp[N],ans;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		int r=sqrt(x);
		for(int i=1;i<r;i++)
			if(x%i==0) dp[i]++,dp[x/i]++;
		if(x%r==0) dp[r]++;
	}

	for(int i=1;i<N;i++)
		if(dp[i]>1) ans=i;
	printf("%d",ans);
}