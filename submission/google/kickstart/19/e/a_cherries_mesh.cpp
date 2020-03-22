#include <bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int t,tc,n,m,u,v,c,arr[N],size[N];
priority_queue <pair<int,pair<int,int>>> pq;

void initialize()
{
	for(int i=1;i<=n;i++) arr[i]=i,size[i]=1;
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
	if(size[root_A]<size[root_B]) arr[root_A]=arr[root_B],size[root_B]+=size[root_A];
	else arr[root_B]=arr[root_A],size[root_A]+=size[root_B];
}

long long kruskal()
{
	int edges=0;
	long long ans=0;
	while(not pq.empty())
	{
		c=pq.top().first;
		u=pq.top().second.first;
		v=pq.top().second.second;
		pq.pop();
		
		if(cycle(u,v)) continue;
		join(u,v);
		ans+=c;
		edges++;
	}

	while(edges<n-1) ans-=2,edges++;
	return -ans;
}

int main()
{
	//Source: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
	//https://www.spoj.com/problems/MST/
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);

		initialize();
		while(m--)
		{
			scanf("%d%d",&u,&v);
			pq.push({-1,{u,v}});
		}

		printf("Case #%d: %lld\n",++tc,kruskal());
	}
}