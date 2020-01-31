#include "bits/stdc++.h"
using namespace std;
const int N=10;
string a;
bool present[N],adj[N][N],vis[N];
vector <int> v;

void topo(int node)
{
	vis[node]=true;
	for(int child=0;child<N;child++)
		if(adj[node][child] and not vis[child])
			topo(child);
	v.push_back(node);
}

int main()
{
	for(int i=0;i<50;i++)
	{
		cin>>a;
		for(int j=0;j<3;j++) present[a[j]-'0']=true;
		adj[a[0]-'0'][a[1]-'0']=adj[a[1]-'0'][a[2]-'0']=true;
	}

	for(int i=0;i<N;i++)
		if(present[i] and not vis[i])
			topo(i);
	while(not v.empty()) printf("%d",v.back()),v.pop_back();
}