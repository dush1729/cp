#include<bits/stdc++.h>
using namespace std;

const int N=14;

int t=1,n,st[N],len[N],i,j,v,ans;
bool visited[N][N];
bool is_valid(int x,int y)
{
    if(x<0 or y<0 or x>=n or y>=st[x]+len[x] or y<st[x]) return false;
    return true;
}
void dfs(int x,int y,int cnt)
{
    visited[x][y]=true;
    ans=max(ans,cnt);
    if(is_valid(x-1,y-2) and visited[x-1][y-2]==false)
    {
        dfs(x-1,y-2,cnt+1);
        visited[x-1][y-2]=false;
    }
    if(is_valid(x-1,y+2) and visited[x-1][y+2]==false)
    {
        dfs(x-1,y+2,cnt+1);
        visited[x-1][y+2]=false;
    }
    if(is_valid(x+1,y+2) and visited[x+1][y+2]==false)
    {
        dfs(x+1,y+2,cnt+1);
        visited[x+1][y+2]=false;
    }
    if(is_valid(x+1,y-2) and visited[x+1][y-2]==false)
    {
        dfs(x+1,y-2,cnt+1);
        visited[x+1][y-2]=false;
    }

    if(is_valid(x-2,y-1) and visited[x-2][y-1]==false)
    {
        dfs(x-2,y-1,cnt+1);
        visited[x-2][y-1]=false;
    }
    if(is_valid(x-2,y+1) and visited[x-2][y+1]==false)
    {
        dfs(x-2,y+1,cnt+1);
        visited[x-2][y+1]=false;
    }
    if(is_valid(x+2,y+1) and visited[x+2][y+1]==false)
    {
        dfs(x+2,y+1,cnt+1);
        visited[x+2][y+1]=false;
    }
    if(is_valid(x+2,y-1) and visited[x+2][y-1]==false)
    {
        dfs(x+2,y-1,cnt+1);
        visited[x+2][y-1]=false;
    }
}
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        ans=1;
        v=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&st[i],&len[i]);
            v+=len[i];
            for(j=st[i];j<st[i]+len[i];j++) visited[i][j]=false;
        }
        dfs(0,st[0],1);
        ans=v-ans;
        if(ans==1) printf("Case %d, 1 square can not be reached.\n",t);
        else printf("Case %d, %d squares can not be reached.\n",t,ans);
        t++;
    }
    return 0;
}
