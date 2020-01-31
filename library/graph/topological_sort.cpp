#include "bits/stdc++.h"
using namespace std;

const int N=3e5+20,C=26;

int n,m,x,y,vis[N],dp[N][C],ans;
char a[N];
bool cycle;
vector <int> adj[N];
queue <int> q; //queue for leaf to parent, stack for parent to leaf

void topo(int node)
{
	vis[node]=1;
	for(auto child:adj[node])
		if(vis[child]==0) topo(child);
		else if(vis[child]==1) cycle=true;
	vis[node]=2;
	q.push(node);
}

int main()
{
	// https://codeforces.com/contest/919/problem/D
	scanf("%d%d %s",&n,&m,a+1);
	for(int i=1;i<=m;i++) scanf("%d%d",&x,&y),adj[x].push_back(y);

	for(int i=1;i<=n;i++)
		if(vis[i]==0) topo(i);

	while(not q.empty())
	{
		int node=q.front();
		q.pop();

		dp[node][a[node]-'a']=1;
		for(auto child:adj[node])
			for(int c=0;c<C;c++)
				dp[node][c]=max(dp[node][c],dp[child][c]+(a[node]==c+'a')),ans=max(ans,dp[node][c]);
	}

	printf("%d",cycle?-1:ans);
}