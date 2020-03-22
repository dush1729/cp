#include "bits/stdc++.h"
using namespace std;
const int N=1e5+20;
int t,n,k,a[N],tc;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++) cin>>a[i];

		sort(a,a+n);
		long long s=0;
		for(int i=0;i<k;i++) s+=a[k-1]-a[i];
		long long ans=s;
		for(int i=k;i<n;i++)
		{
			s-=a[i-1]-a[i-k];
			s+=1ll*(a[i]-a[i-1])*(k-1);
			ans=min(ans,s);
		}
		cout<<"Case #"<<++tc<<": "<<ans<<"\n";
	}
}