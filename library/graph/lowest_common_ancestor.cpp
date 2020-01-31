#include "bits/stdc++.h"
using namespace std;

const int N=1e3+20;

int tc,n,m,x,q,u,v,lev[N],par[N],lca[N][(int)log2(N)+10];
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
	for(int i=1;i<=n;i++)
		for(int j=0;1<<j<=n;j++)
			lca[i][j]=-1;
	for(int i=1;i<=n;i++) lca[i][0]=par[i];
	for(int j=1;1<<j<=n;j++)
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

int main()
{
	scanf("%d",&tc);
	for(int t=1;t<=tc;t++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x);
				adj[x].push_back(i);
				adj[i].push_back(x);
			}
		}

		dfs(1,0,1);
		preprocess();

		scanf("%d",&q);
		printf("Case %d:\n",t);
		while(q--)
		{
			scanf("%d%d",&u,&v);
			printf("%d\n",query(u,v));
		}

		for(int i=1;i<=n;i++) adj[i].clear();
	}
}
