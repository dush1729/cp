#include <bits/stdc++.h>
using namespace std;

const int N=1e5+20;
int n,m,u,v,c,p[N],sz[N];
priority_queue <pair<int,pair<int,int>>> pq;

void init() {for(int i=1;i<=n;i++) p[i]=i,sz[i]=1;}

int root(int i) {return p[i]==i?i:p[i]=root(p[i]);}

bool cycle(int a,int b) {return root(a)==root(b);}

void join(int a,int b)
{
	a=root(a),b=root(b);
	if(sz[a]<sz[b]) swap(a,b);
	p[b]=p[a],sz[a]+=sz[b];
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

	init();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		pq.push({-c,{u,v}});
	}

	printf("%lld",kruskal());
}