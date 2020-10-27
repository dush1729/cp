#include "bits/stdc++.h"
using namespace std;

int t,x,y;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);

		int l=max(x,y);
		long long ans=1ll*(l-1)*(l-1);
		if(l%2)
		{
			if(x==l) ans+=y;
			else ans+=l-(x-l);
		}
		else
		{
			if(y==l) ans+=x;
			else ans+=l-(y-l);
		}

		printf("%lld\n",ans);
	}
}