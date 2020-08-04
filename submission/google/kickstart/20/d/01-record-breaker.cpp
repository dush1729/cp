#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int t,n,a[N],mx[N];

int main()
{
	ios::sync_with_stdio(false);
	mx[0]=INT_MIN;

	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			mx[i]=max(mx[i-1],a[i]);
		}

		a[n+1]=INT_MIN;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]>mx[i-1] and a[i]>a[i+1]) ans++;

		cout<<"Case #"<<tc<<": "<<ans<<"\n";
	}
}