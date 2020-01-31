#include "bits/stdc++.h"
using namespace std;
const int N=1e6+1;
int sum[N],vis[N],en[N],ans=INT_MAX;

void go(int i,int t)
{
	vis[i]=1;
	en[i]=t;
	if(sum[i]>=N or vis[sum[i]]==2)
	{
		vis[i]=2;
		return;
	}
	if(vis[sum[i]]==0) go(sum[i],t+1);
	else if(t-en[sum[i]]==27) //vis[i]==1 ie cycle present
	{
		ans=min(ans,i);
		for(int j=sum[i];j!=i;j=sum[j]) ans=min(ans,j);
	}
	vis[i]=2;
}

int main()
{
	for(int i=1;i<N;i++)
		for(int j=2*i;j<N;j+=i)
			sum[j]+=i;

	//First found out that maximum cycle length is 27
	for(int i=2;i<N;i++)
		if(vis[i]==0) go(i,1);
	cout<<ans;
}