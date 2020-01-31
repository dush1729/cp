#include <bits/stdc++.h>
using namespace std;

const int N=1e5+20;
int n,m,u,v,c,arr[N],sz[N];
priority_queue <pair<int,pair<int,int>>> pq;

void initialize()
{
	for(int i=1;i<=n;i++) arr[i]=i,sz[i]=1;
}

int root(int i)
{
	return arr[i]==i?i:root(arr[i]);
}

bool cycle(int A,int B)
{
	return root(A)==root(B);
}

void join(int A,int B)
{
	int root_A=root(A);
	int root_B=root(B);
	if(sz[root_A]<sz[root_B]) arr[root_A]=arr[root_B],sz[root_B]+=sz[root_A];
	else arr[root_B]=arr[root_A],sz[root_A]+=sz[root_B];
}

long long kruskal()
{
	long long ans=0;
	while(not pq.empty())
	{
		int c=pq.top().first;
		int u=pq.top().second.first;
		int v=pq.top().second.second;
		pq.pop();
		
		if(cycle(u,v)) continue;
		join(u,v);
		ans+=c;
	}
	return -ans;
}

int main()
{
	//Source: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
	//https://www.spoj.com/problems/MST/
	scanf("%d%d",&n,&m);

	initialize();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		pq.push({-c,{u,v}});
	}

	printf("%lld",kruskal());
}