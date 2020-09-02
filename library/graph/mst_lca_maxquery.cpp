//https://codeforces.com/contest/609/problem/E
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+20,L=log2(N)+5;

int n,m,u[N],v[N],c[N],p[N],sz[N];
int lev[N],par[N],lca[N][L],mx[N][L];
priority_queue <pair<int,pair<int,int>>> pq;
vector <pair <int,int>> adj[N];
set <pair <int,int>> s;

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
		int c=-pq.top().first;
		int u=pq.top().second.first;
		int v=pq.top().second.second;
		pq.pop();

		if(cycle(u,v)) continue;
		join(u,v);
		ans+=c;

		s.insert({u,v});
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}
	return ans;
}

void dfs(int node,int parent,int depth,int edge)
{
	par[node]=parent;
	lev[node]=depth;
	mx[node][0]=edge;
	for(auto p:adj[node])
		if(p.first!=parent) dfs(p.first,node,depth+1,p.second);
}

void preprocess()
{
	dfs(1,0,1,INT_MIN);
	for(int i=1;i<=n;i++)
		for(int j=0;1<<j<=n;j++)
			lca[i][j]=-1;
	for(int i=2;i<=n;i++) lca[i][0]=par[i];
	for(int j=1;1<<j<n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(lca[i][j-1]==-1) continue;
			lca[i][j]=lca[lca[i][j-1]][j-1];
			mx[i][j]=max(mx[i][j-1],mx[lca[i][j-1]][j-1]);
		}
	}
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
	scanf("%d%d",&n,&m);

	init();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
		pq.push({-c[i],{u[i],v[i]}});
	}

	long long ans=kruskal();
	preprocess();
	for(int i=0;i<m;i++)
	{
		if(s.find({u[i],v[i]})!=s.end()) printf("%lld\n",ans);
		else
		{
			int father=query(u[i],v[i]);
			int k1=lev[u[i]]-lev[father],k2=lev[v[i]]-lev[father];


			int mxval=INT_MIN;
			if(k1!=0)
			{
				for(int j=L-1;j>=0;j--)
				{
					if(k1&(1<<j))
					{
						mxval=max(mxval,mx[u[i]][j]);
						u[i]=lca[u[i]][j];
					}
				}
			}
			if(k2!=0)
			{
				for(int j=L-1;j>=0;j--)
				{
					if(k2&(1<<j))
					{
						mxval=max(mxval,mx[v[i]][j]);
						v[i]=lca[v[i]][j];
					}
				}
			}
			printf("%lld\n",ans-mxval+c[i]);
		}
	}
}