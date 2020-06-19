#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20,MOD=1e9+7;

int n,m,c[N],u,v;
bool vis[N];
stack <int> s;
vector <int> adj[N],rev[N];
long long sum,ways=1;
map <int,int> f;

void init()
{
	for(int i=1;i<=n;i++) vis[i]=false;
}

void dfs(int node)
{
	vis[node]=true;
	for(auto i:adj[node])
		if(not vis[i]) dfs(i);
	s.push(node);
}

void dfs2(int node)
{
	vis[node]=true;
	f[c[node]]++;
	for(auto i:rev[node])
		if(not vis[i]) dfs2(i);
}

int main()
{
	//https://codeforces.com/contest/427/problem/C
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);

	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		rev[v].push_back(u);
	}

	//kosaraju
	for(int i=1;i<=n;i++)
		if(not vis[i]) dfs(i);

	init();

	while(not s.empty())
	{
		u=s.top();
		s.pop();
		if(vis[u]) continue;

		//new strongly connected component starts here
		f.clear();
		dfs2(u);
		sum+=f.begin()->first;
		ways=(ways*f.begin()->second)%MOD;
	}

	printf("%lld %lld",sum,ways);
}