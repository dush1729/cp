#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,u,v,d[N],ans;
vector <int> adj[N];

void dfs(int node,int parent,int depth)
{
	d[node]=depth;
	ans=max(ans,depth);
	for(auto child:adj[node])
		if(child!=parent) dfs(child,node,depth+1);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1,0,0);
	dfs(max_element(d+1,d+n+1)-d,0,0);
	printf("%d",ans);
}