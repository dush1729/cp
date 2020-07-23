#include "bits/stdc++.h"
using namespace std;

const int MOD=1e9+7;

int t,a,b,c;

int mul(int a,int b,int mod) {return (1ll*a*b)%mod;}

int power(int a,int b,int mod)
{
	int num=a,ans=1;
	while(b)
	{
		if(b&1) ans=mul(ans,num,mod);
		b>>=1;
		num=mul(num,num,mod);
	}
	return ans;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		cout<<power(a,power(b,c,MOD-1),MOD)<<"\n";
	}
}