#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

int t,tc,n,k,a[N];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);

		int lo=1,hi=a[n-1],ans;
		while(lo<=hi)
		{
			int mid=(lo+hi)/2,cuts=0;
			for(int i=1;i<n;i++)
			{
				if(a[i]-a[i-1]<=mid) continue;
				cuts+=(a[i]-a[i-1]-1)/mid;
			}
			if(cuts<=k) ans=mid,hi=mid-1;
			else lo=mid+1;
		}

		printf("Case #%d: %d\n",++tc,ans);
	}
}