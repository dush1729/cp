#include "bits/stdc++.h"
using namespace std;

const int N=1e6+20,MOD=1e9+7;

int t,n,r;
int f[N],ie[N];

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

int inverse_euler(int n)
{
	return power(n,MOD-2);
}

int ncr(int n,int r)
{
	return mul(f[n],mul(ie[r],ie[n-r]));
}

void precompute()
{
	f[0]=1;
	for(int i=1;i<N;i++) f[i]=mul(f[i-1],i);
	for(int i=0;i<N;i++) ie[i]=inverse_euler(f[i]);
}

int main()
{
	precompute();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&r);
		printf("%d\n",ncr(n,r));
	}
}