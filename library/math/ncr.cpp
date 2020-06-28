#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20,MOD=(int)(1e9)+7;

int f[N],ie[N],i;

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
	return mul(f[n],mul(ie[r],ir[n-r]));
}

void precompute()
{
	f[0]=1;
	for(int i=1;i<N;i++) f[i]=mul(f[i-1],i);
	for(int i=0;i<N;i++) ie[i]=inverse_euler(f[i]);
}

int main()
{
	//https://codeforces.com/contest/560/problem/E
	precompute();
}