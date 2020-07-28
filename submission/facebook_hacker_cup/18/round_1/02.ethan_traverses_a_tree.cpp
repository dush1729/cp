#include "bits/stdc++.h"
using namespace std;
const int N=2e3+20;
int t,n,k,l[N],r[N],ans[N],col,i,testcase;
vector <int> pre,post,adj[N];
bool impossible;

void dfs(int node)
{
	pre.push_back(node);
	if(l[node]) dfs(l[node]);
	if(r[node]) dfs(r[node]);
	post.push_back(node);
}

void start_coloring(int node)
{
	ans[node]=col;
	for(auto child:adj[node])
		if(not ans[child]) start_coloring(child);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		col=1,impossible=true,pre.clear(),post.clear();

		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) ans[i]=0,adj[i].clear();
		for(i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);

		dfs(1);
		for(i=0;i<n;i++)
			adj[pre[i]].push_back(post[i]),adj[post[i]].push_back(pre[i]);

		for(i=1;i<=n;i++)
		{
			if(not ans[i]) start_coloring(i),col++;
			if(col==k+1) col=k,impossible=false;
		}

		printf("Case #%d: ",++testcase);
		if(impossible) printf("Impossible");
		else for(i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}