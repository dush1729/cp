#include "bits/stdc++.h"
using namespace std;

const int N=60;

int t,n;
string in,out,ans;
bool adj[N][N],vis[N];

void go(int node)
{
	vis[node]=true;
	for(int child=0;child<n;child++)
		if(adj[node][child] and not vis[child]) go(child);
}

int main()
{
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		cin>>n>>in>>out;
		cout<<"Case #"<<tc<<":\n";

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(abs(i-j)>1) adj[i][j]=false;
				else if(out[i]=='Y' and in[j]=='Y') adj[i][j]=true;
				else adj[i][j]=false;
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int i=0;i<n;i++) vis[i]=false;
			go(i);
			for(int i=0;i<n;i++) cout<<(vis[i]?'Y':'N');
			cout<<"\n";
		}
	}
}