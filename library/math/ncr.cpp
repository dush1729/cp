#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20,MOD=(int)(1e9)+7;

int f[N],ie[N],i;

int power(int a,int b)
{
	int num=a,ans=1;
	for(int i=0;i<31;i++)
	{
		if(b&(1<<i)) ans=(1ll*ans*num)%MOD;
		num=(1ll*num*num)%MOD;
	}
	return ans;
}

int inverse_euler(int n)
{
	return power(n,MOD-2);
}

int ncr(int n,int r)
{
	return (1LL*f[n]*((1LL*ie[r]*ie[n-r])%MOD))%MOD;
}

void precompute()
{
	f[0]=1;
	for(int i=1;i<N;i++) f[i]=(1LL*f[i-1]*i)%MOD;
	for(int i=0;i<N;i++) ie[i]=inverse_euler(f[i]);
}

int main()
{
	//https://codeforces.com/contest/560/problem/E
	precompute();
}