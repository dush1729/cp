// https://codeforces.com/contest/872/problem/B
#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20,L=log(N)+5;

int n,k,a[N];

int st[N][L],lg[N];

void build()
{
	for(int i=2;i<N;i++) lg[i]=lg[i>>1]+1;
	for(int j=0;j<L;j++)
	{
		for(int i=1;i+(1<<j)<=n+1;i++)
		{
			if(j==0) st[i][0]=a[i];
			else st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}

// O(lgn) query for associative functions
int query(int l,int r)
{
	int s=INT_MAX;
	for(int j=L-1;j>=0;j--)
	{
		if((1<<j)>r-l+1) continue;
		s=min(s,st[l][j]);
		l+=1<<j;
	}
	return s;
}

// O(1) query for idempotent functions
int queryf(int l,int r)
{
	int j=lg[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build();

	if(k==1) printf("%d",*min_element(a+1,a+n+1));
	else if(k>2) printf("%d",*max_element(a+1,a+n+1));
	else
	{
		int ans=INT_MIN;
		for(int i=1;i+1<=n;i++) ans=max({ans,queryf(1,i),queryf(i+1,n)});
		printf("%d",ans);
	}
}