#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,u,v,dp[N][2];
vector <int> adj[N];

int dfs(int node,int parent,bool chosen)
{
	if(dp[node][chosen]!=-1) return dp[node][chosen];
	dp[node][chosen]=0;
	for(auto child:adj[node])
		if(child!=parent) dp[node][chosen]+=dfs(child,node,true);
	if(not chosen) return dp[node][chosen];

	int sum=dp[node][chosen];
	for(auto child:adj[node])
		if(child!=parent)
			dp[node][chosen]=max(dp[node][chosen],sum-dp[child][true]+dfs(child,node,false)+1);
	return dp[node][chosen];
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

	for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=-1;
	printf("%d\n",dfs(1,0,true));
}