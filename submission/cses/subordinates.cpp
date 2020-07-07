#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,x,dp[N];
vector <int> adj[N];

int dfs(int node)
{
	dp[node]=1;
	for(auto child:adj[node])
		dp[node]+=dfs(child);
	return dp[node];
}

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		adj[x].push_back(i);
	}

	dfs(1);
	for(int i=1;i<=n;i++) printf("%d ",--dp[i]);
}