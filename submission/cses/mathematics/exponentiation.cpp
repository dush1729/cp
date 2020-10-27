#include "bits/stdc++.h"
using namespace std;

const int MOD=1e9+7;

int t,a,b;

int mul(int a,int b) {return (1ll*a*b)%MOD;}

int power(int a,int b)
{
	int num=a,ans=1;
	while(b)
	{
		if(b&1) ans=mul(ans,num);
		b>>=1;
		num=mul(num,num);
	}
	return ans;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<power(a,b)<<"\n";
	}
}