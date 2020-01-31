#include<bits/stdc++.h>
using namespace std;

const int N=1009;

int t,n,m,i,j,mxlen;
char a[N][N];
bool visited[N][N];
pair <int,int> leaf,start;
void dfs(pair <int,int> node,int len)
{
    int x=node.first,y=node.second;
    visited[x][y]=true;
    if(mxlen<len)
    {
        leaf=node;
        mxlen=len;
    }
    if(x+1<n and a[x+1][y]!='#' and visited[x+1][y]==false) dfs({x+1,y},len+1);
    if(x-1>=0 and a[x-1][y]!='#' and visited[x-1][y]==false) dfs({x-1,y},len+1);
    if(y+1<m and a[x][y+1]!='#' and visited[x][y+1]==false) dfs({x,y+1},len+1);
    if(y-1>=0 and a[x][y-1]!='#' and visited[x][y-1]==false) dfs({x,y-1},len+1);
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        swap(n,m);
        for(i=0;i<n;i++) scanf(" %s",a[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]=='.') start.first=i, start.second=j;
                visited[i][j]=false;
            }
        }
        mxlen=-1;
        dfs(start,0);
        for(i=0;i<n;i++) for(j=0;j<m;j++) visited[i][j]=false;
        mxlen=-1;
        dfs(leaf,0);
        printf("Maximum rope length is %d.\n",mxlen);
    }
    return 0;
}
