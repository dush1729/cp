#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

int n,m,u,v,c;
long long dp[N],parent[N];
vector <pair <int,int>> adj[N];
priority_queue <pair <long long,int>> pq;
vector <int> ans;

void add(int node,int father,long long dist)
{
	dp[node]=dist;
	pq.push({-dist,node});
	parent[node]=father;
}

int main()
{
	//https://codeforces.com/contest/20/problem/C
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&c);
		adj[u].push_back({c,v});
		adj[v].push_back({c,u});
	}

	for(int i=1;i<=n;i++) dp[i]=LLONG_MAX;

	add(1,0,0);
	while(not pq.empty())
	{
		int node=pq.top().second;
		pq.pop();

		for(auto p:adj[node])
		{
			int cost=p.first,child=p.second;
			if(dp[child]<=dp[node]+cost) continue;
			add(child,node,dp[node]+cost);
		}
	}

	if(parent[n]==0) printf("-1");
	else
	{
		for(int i=n;i!=0;i=parent[i]) ans.push_back(i);
		reverse(ans.begin(),ans.end());
		for(auto i:ans) printf("%d ",i);
	}
}