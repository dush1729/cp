#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int t,n,a[N],tc;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];

		int ans=0;
		for(int i=1;i+1<n;i++)
			if(a[i]>a[i-1] and a[i]>a[i+1]) ans++;

		cout<<"Case #"<<++tc<<": "<<ans<<"\n";
	}
}