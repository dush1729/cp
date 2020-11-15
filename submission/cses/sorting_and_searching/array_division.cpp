#include "bits/stdc++.h"
using namespace std;

#define ll long long

const int N=2e5+20;

int n,k,a[N];
ll ans;

int main()
{
	ios::sync_with_stdio(0);

	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];

	ll lo=*max_element(a,a+n),hi=1e18;
	while(lo<=hi)
	{
		ll mid=(lo+hi)/2,s=0;
		int cut=0;
		for(int i=0;i<n;i++)
		{
			s+=a[i];
			if(s>mid) s=a[i],cut++;
		}

		if(cut<=k-1) hi=mid-1,ans=mid;
		else lo=mid+1;
	}

	cout<<ans;
}