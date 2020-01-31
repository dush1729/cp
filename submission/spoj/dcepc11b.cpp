#include "bits/stdc++.h"
using namespace std;
int t,n,p;

int power(int a,int b,int mod)
{
	int num=a,ans=1;
	for(int i=0;i<31;i++)
	{
		if(b&(1<<i)) ans=(1ll*ans*num)%mod;
		num=(1ll*num*num)%mod;
	}
	return ans;
}

int inv(int n,int mod)
{
	return power(n,mod-2,mod);
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>p;

		int ans=0;
		if(n<p)
		{
			ans=p-1;
			for(int i=p-1;i>n;i--)
				ans=(1ll*ans*inv(i,p))%p;
		}
		cout<<ans<<"\n";
	}
}