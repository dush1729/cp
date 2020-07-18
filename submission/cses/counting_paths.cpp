#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20,L=log2(N)+20;

int n,m,u,v,lev[N],par[N],lca[N][L],dp[N],ans[N];
vector <int> adj[N];

void dfs(int node,int parent,int depth)
{
	par[node]=parent;
	lev[node]=depth;
	for(auto child:adj[node])
		if(child!=parent) dfs(child,node,depth+1);
}

void preprocess()
{
	dfs(1,0,1);
	for(int i=1;i<=n;i++)
		for(int j=0;1<<j<=n;j++)
			lca[i][j]=-1;
	for(int i=2;i<=n;i++) lca[i][0]=par[i];
	for(int j=1;1<<j<n;j++)
		for(int i=1;i<=n;i++)
			if(lca[i][j-1]!=-1) lca[i][j]=lca[lca[i][j-1]][j-1];
}

int query(int u,int v)
{
	if(lev[u]<lev[v]) swap(u,v);
	int lg=log2(lev[u]);
	for(int i=lg;i>=0;i--)
		if(lev[u]-(1<<i)>=lev[v]) u=lca[u][i];
	if(u==v) return u;
	for(int i=lg;i>=0;i--)
		if(lca[u][i]!=-1 and lca[u][i]!=lca[v][i])
			u=lca[u][i],v=lca[v][i];
	return par[u];
}

int dfs(int node,int parent)
{
	for(auto child:adj[node])
		if(child!=parent) dp[node]+=dfs(child,node);
	return dp[node];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	preprocess();

	while(m--)
	{
		scanf("%d%d",&u,&v);
		int lca=query(u,v);
		dp[u]++;
		dp[v]++;
		dp[lca]-=2;
		ans[lca]++;
	}

	dfs(1,0);
	for(int i=1;i<=n;i++) printf("%d ",dp[i]+ans[i]);
}