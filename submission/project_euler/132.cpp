#include "bits/stdc++.h"
using namespace std;
const int N=2e5+20,M=1e9;
bool prime[N];

int power(int a,int b,int mod)
{
	if(b==0) return 1;
	int x=power(a,b/2,mod);
	x=(1ll*x*x)%mod;
	if(b&1) x=(1ll*x*a)%mod;
	return x;
}

int f(int n,int mod)
{
	if(n<2) return 1;
	int x=f(n/2,mod);
	int y=power(10,(n+1)/2,mod);
	x=(1ll*y*x+x)%mod;
	if(n%2) x=(x+power(10,n/2,mod))%mod;
	return x;
}

int main()
{
	for(int i=2;i<N;i++) prime[i]=true;
	for(int i=2;i*i<N;i++)
		if(prime[i])
			for(int j=i*i;j<N;j+=i)
				prime[j]=false;

	int ans=0;
	for(int cnt=0,num=2;cnt<40;num++)
	{
		if(prime[num] and f(M,num)==0)
		{
			ans+=num;
			cnt++;
		}
	}
	cout<<ans<<endl;
}