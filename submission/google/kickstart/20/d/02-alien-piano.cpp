#include "bits/stdc++.h"
using namespace std;

const int N=1e4+20;

int t,n,a[N];

int f()
{
	int ans=0;
	for(int i=1,cnt=0;i<n;i++)
	{
		if(a[i]>a[i-1]) cnt++;
		else if(a[i]<a[i-1]) cnt=0;
		if(cnt==4) ans++,cnt=0;
	}
	for(int i=1,cnt=0;i<n;i++)
	{
		if(a[i]<a[i-1]) cnt++;
		else if(a[i]>a[i-1]) cnt=0;
		if(cnt==4) ans++,cnt=0;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];

		cout<<"Case #"<<tc<<": "<<f()<<"\n";
	}
}