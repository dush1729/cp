#include "bits/stdc++.h"
using namespace std;

int n,x;
long long s,ans=LLONG_MIN;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		s+=x;
		ans=max(ans,s);
		s=max(s,0ll);
	}
	printf("%lld",ans);
}