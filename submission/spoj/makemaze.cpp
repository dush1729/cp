#include<bits/stdc++.h>
using namespace std;
const int N=25;
int t,n,m,i,j,cnt,sx,sy,ex,ey;
char a[N][N];
bool visited[N][N];
void run()
{
    for(j=0;j<m;j++)
    {
        if(visited[0][j]==false)
        {
            if(a[0][j]=='.')
            {
                if(cnt==0) sx=0, sy=j;
                else       ex=0, ey=j;
                cnt++;
            }
            visited[0][j]=true;
        }
        if(visited[n-1][j]==false)
        {
            if(a[n-1][j]=='.')
            {
                if(cnt==0) sx=n-1, sy=j;
                else       ex=n-1, ey=j;
                cnt++;
            }
            visited[n-1][j]=true;
        }
    }
    for(i=0;i<n;i++)
    {
        if(visited[i][0]==false)
        {
            if(a[i][0]=='.')
            {
                if(cnt==0) sx=i, sy=0;
                else       ex=i, ey=0;
                cnt++;
            }
            visited[i][0]=true;
        }
        if(visited[i][m-1]==false)
        {
            if(a[i][m-1]=='.')
            {
                if(cnt==0) sx=i, sy=m-1;
                else       ex=i, ey=m-1;
                cnt++;
            }
            visited[i][m-1]=true;
        }
    }
}
bool valid(int x,int y)
{
    if(x<0 or y<0 or x>=n or y>=m or visited[x][y]==true or a[x][y]=='#') return false;
    return true;
}
int dx[]={ 0, 0,+1,-1};
int dy[]={+1,-1, 0, 0};
void dfs(int x,int y)
{
    visited[x][y]=true;
    for(int i=0;i<4;i++)
        if(valid(x+dx[i],y+dy[i])==true) dfs(x+dx[i],y+dy[i]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf(" %s",a[i]);
            for(j=0;j<m;j++) visited[i][j]=false;
        }
        cnt=0;
        run();
        if(cnt!=2)
        {
            printf("invalid\n");
            continue;
        }
        for(i=0;i<n;i++) for(j=0;j<m;j++) visited[i][j]=false;
        dfs(sx,sy);
        if(visited[ex][ey]==true) printf("valid\n");
        else printf("invalid\n");
    }
    return 0;
}
