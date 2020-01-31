#include "bits/stdc++.h"
using namespace std;
const int N=1e8;
int prime[N];
long long ans;
int main()
{
	for(int i=2;i*i<N;i++)
		if(prime[i]==0)
			for(int j=i*i;j<N;j+=i) prime[j]=1;
	for(int i=2;i<N;i++) prime[i]^=1,prime[i]+=prime[i-1];

	for(int i=2;i*i<N;i++)
		if(prime[i]-prime[i-1]==1) ans+=prime[(N-1)/i]-prime[i-1];
	cout<<ans;
}