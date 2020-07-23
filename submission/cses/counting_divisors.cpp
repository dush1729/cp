#include "bits/stdc++.h"
using namespace std;

const int N=1e6+20;

int t,n,dp[N];

int main()
{
	for(int i=1;i<N;i++)
		for(int j=i;j<N;j+=i)
			dp[j]++;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
}