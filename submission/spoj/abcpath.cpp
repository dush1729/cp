#include<bits/stdc++.h>
using namespace std;

const int N=60;
int t,h,w,i,j,ans;
char a[N][N];
bool visited[N][N];
int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};
void initialize()
{
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) visited[i][j]=false;
}
bool valid(int x,int y,char curr)
{
    if(x<0 or y<0 or x>=h or y>=w or visited[x][y]==true or curr=='Z') return false;
    return true;
}
void dfs(int x,int y,char curr)
{
    visited[x][y]=true;
    ans=max(ans,curr-'A'+1);
    for(int i=0;i<8;i++)
    {
        if(valid(x+dx[i],y+dy[i],curr) and a[x+dx[i]][y+dy[i]]==curr+1)
            dfs(x+dx[i],y+dy[i],curr+1);
    }
}
int main()
{
    while(1)
    {
        scanf("%d%d",&h,&w);
        if(h==0 and w==0) break;
        for(i=0;i<h;i++) scanf(" %s",a[i]);
        ans=0;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(a[i][j]=='A') initialize(), dfs(i,j,'A');
            }
        }
        printf("Case %d: %d\n",++t,ans);
    }
    return 0;
}
