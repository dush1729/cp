#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

int n,m,u,v,dp[N];
vector <int> adj[N],ans;
queue <int> q;

void add(int node,int parent)
{
	q.push(node);
	dp[node]=parent;
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

	add(1,0);
	while(not q.empty())
	{
		int node=q.front();
		q.pop();

		for(auto child:adj[node])
			if(!dp[child]) add(child,node);
	}

	if(!dp[n]) printf("IMPOSSIBLE");
	else
	{
		for(int i=n;i!=1;i=dp[i]) ans.push_back(i);
		ans.push_back(1);
		reverse(ans.begin(),ans.end());
		printf("%d\n",ans.size());
		for(auto i:ans) printf("%d ",i);
	}
}