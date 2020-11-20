#include "bits/stdc++.h"
using namespace std;

const int N=1e3+20,M=1e5+20;

int n,m,h[N],s[N],dp[M];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&h[i]);
	for(int i=0;i<n;i++) scanf("%d",&s[i]);

	for(int i=0;i<n;i++)
		for(int j=m;j>=h[i];j--)
			dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
	printf("%d",*max_element(dp,dp+m+1));
}