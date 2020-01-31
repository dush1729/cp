#include "bits/stdc++.h"
using namespace std;
const int N=1e8+1;
bool ok[N+1],prime[N+1];
long long ans;

int main()
{
	for(int i=1;i<=N;i++) prime[i]=ok[i]=true;
	prime[1]=false;
	for(int i=2;i*i<=N;i++)
		if(prime[i])
			for(int j=i*i;j<=N;j+=i)
				prime[j]=false;
	for(int i=1;i*i<N;i++)
		for(int j=i*i;j<N;j+=i)
			ok[j]&=prime[i+j/i];
	for(int i=1;i<N;i++)
		if(ok[i]) ans+=i;
	cout<<ans<<endl;
}