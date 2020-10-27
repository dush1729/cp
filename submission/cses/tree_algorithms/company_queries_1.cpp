#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,m,q,u,k,lev[N],par[N],lca[N][(int)log2(N)+10];
vector <int> adj[N];

void dfs(int node,int parent,int depth)
{
	par[node]=parent;
	lev[node]=depth;
	for(auto child:adj[node]) dfs(child,node,depth+1);
}

void preprocess()
{
	for(int i=1;i<=n;i++)
		for(int j=0;1<<j<=n;j++)
			lca[i][j]=-1;
	for(int i=1;i<=n;i++) lca[i][0]=par[i];
	for(int j=1;1<<j<=n;j++)
		for(int i=1;i<=n;i++)
			if(lca[i][j-1]!=-1) lca[i][j]=lca[lca[i][j-1]][j-1];
}

int query(int u,int k)
{
	if(lev[u]<=k) return -1;
	int lg=log2(lev[u]);
	for(int i=lg;i>=0;i--)
		if(k>=(1<<i)) u=lca[u][i],k-=(1<<i);
	return u;
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&u);
		adj[u].push_back(i);
	}

	dfs(1,0,1);
	preprocess();

	while(q--)
	{
		scanf("%d%d",&u,&k);
		printf("%d\n",query(u,k));
	}
}
