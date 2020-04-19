#include "bits/stdc++.h"
using namespace std;

const int N=1e3+20;

int t,n,tc;
long long a[N],d;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>a[i];

		long long lo=1,hi=d,ans=-1;
		while(lo<=hi)
		{
			long long mid=(lo+hi)/2;

			long long pv=mid;
			for(int i=0;i<n;i++)
			{
				if(pv%a[i]==0) continue;
				pv+=a[i]-pv%a[i];
			}

			if(pv<=d) lo=mid+1,ans=mid;
			else hi=mid-1;
		}

		cout<<"Case #"<<++tc<<": "<<ans<<"\n";
	}
}