#include "bits/stdc++.h"
using namespace std;
const int n=15;
int a[n][n],dp[1<<n],bit[1<<n];
int main()
{
	for(int i=1;i<(1<<n);i++) bit[i]=bit[i>>1]+(i&1);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	for(int mask=0;mask<(1<<n);mask++)
	{
		for(int i=0;i<n;i++)
		{
			if(mask&(1<<i)) continue;
			dp[mask^(1<<i)]=max(dp[mask^(1<<i)],dp[mask]+a[bit[mask]][i]);
		}
	}

	printf("%d\n",dp[(1<<n)-1]);
}