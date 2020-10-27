#include "bits/stdc++.h"
using namespace std;

const int N=20,M=1<<N;

int n,a[N];
long long s,dp[M],ans=LLONG_MAX;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]),s+=a[i];

	for(int mask=0;mask<(1<<n);mask++)
	{
		for(int i=0;i<n;i++)
			if(mask&(1<<i)) dp[mask]+=a[i];
		ans=min(ans,abs(s-2*dp[mask]));
	}

	printf("%lld",ans);
}