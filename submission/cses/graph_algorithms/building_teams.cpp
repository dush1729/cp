#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

int n,m,u,v,c[N];
vector <int> adj[N];
bool no;

void dfs(int node,int color)
{
	c[node]=color;
	for(auto child:adj[node])
		if(!c[child]) dfs(child,3-c[node]);
		else if(c[child]==c[node]) no=true;
}

int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1;i<=n;i++)
		if(!c[i]) dfs(i,1);

	if(no) printf("IMPOSSIBLE");
	else
	{
		for(int i=1;i<=n;i++) printf("%d ",c[i]);
	}
}