#include<bits/stdc++.h>
using namespace std;

const int N=1e5+9;

int t,n,i,x,y,leaf,mxlen;
vector <int> adj[N];
bool visited[N];
void dfs(int node,int len)
{
    visited[node]=true;
    if(mxlen<len)
    {
        mxlen=len;
        leaf=node;
    }
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(visited[child]==false) dfs(child,len+1);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) adj[i].clear(),visited[i]=false;
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        mxlen=-1;
        dfs(0,0);
        for(i=0;i<n;i++) visited[i]=false;
        mxlen=-1;
        dfs(leaf,0);
        printf("%d\n",(mxlen+1)/2);
    }
    return 0;
}
