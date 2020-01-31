#include "bits/stdc++.h"
using namespace std;
const int N=20000000,R=15000000;
int lp[N+1],m[N+1];
long long ans;

void go(int x,int c)
{
	while(x!=1) m[lp[x]]+=c,x/=lp[x];
}

int main()
{
	for(int i=2;i*i<=N;i++)
		if(lp[i]==0)
			for(int j=i*i;j<=N;j+=i)
				if(lp[j]==0) lp[j]=i;
	for(int i=2;i<=N;i++) if(lp[i]==0) lp[i]=i;

	for(int i=2;i<=N-R;i++) go(i,-1);
	for(int i=R+1;i<=N;i++) go(i,1);
	for(int i=2;i<=N;i++) ans+=i*m[i];
	cout<<ans<<endl;
}