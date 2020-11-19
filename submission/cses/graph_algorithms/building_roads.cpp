#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

int n,m,u,v;
vector <int> adj[N],ans;
bool vis[N];

void dfs(int node)
{
	vis[node]=true;
	for(auto child:adj[node])
		if(not vis[child]) dfs(child);
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
	{
		if(vis[i]) continue;
		dfs(i);
		ans.push_back(i);
	}

	printf("%d\n",ans.size()-1);
	for(int i=1;i<ans.size();i++) printf("%d %d\n",ans[i-1],ans[i]);
}