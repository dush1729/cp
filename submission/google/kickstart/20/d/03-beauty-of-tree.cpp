#include "bits/stdc++.h"
using namespace std;

const int N=5e5+20;

int t,n,a,b,x,dp[2][N];
vector <int> adj[N],v;
long long ans;

void reset()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		adj[i].clear();
		dp[0][i]=dp[1][i]=0;
	}
}

void dfs(int node)
{
	v.push_back(node);
	dp[0][node]++;
	dp[1][node]++;
	for(auto child:adj[node]) dfs(child);

	ans+=1ll*(dp[0][node]+dp[1][node])*n-1ll*dp[0][node]*dp[1][node];
	int l=v.size();
	if(l>a) dp[0][v[l-a-1]]+=dp[0][node];
	if(l>b) dp[1][v[l-b-1]]+=dp[1][node];
	v.pop_back();
}

int main()
{
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&x);
			adj[x].push_back(i);
		}

		dfs(1);
		printf("Case #%d: %.12f\n",tc,1.*ans/(1ll*n*n));

		reset();
	}
}