#include "bits/stdc++.h"
using namespace std;
const int N=20;
int t,n,a[N][N],bit[1<<N];
long long dp[1<<N];
int main()
{
	for(int i=1;i<(1<<N);i++) bit[i]=bit[i>>1]+(i&1);

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);

		dp[0]=1;
		for(int i=1;i<(1<<n);i++) dp[i]=0;
		for(int mask=0;mask<(1<<n);mask++)
		{
			for(int i=0;i<n;i++)
			{
				if((mask&(1<<i)) or a[bit[mask]][i]==0) continue;
				dp[mask|(1<<i)]+=dp[mask];
			}
		}

		printf("%lld\n",dp[(1<<n)-1]);
	}
}