#include "bits/stdc++.h"
using namespace std;

const int N=1e3+20;

int n,m,ans;
char a[N][N];
int dx[]={+1,-1, 0, 0};
int dy[]={ 0, 0,+1,-1};
bool vis[N][N];

bool invalid(int x,int y)
{
	return min(x,y)<0 or x>=n or y>=m or vis[x][y] or a[x][y]=='#';
}

void dfs(int x,int y)
{
	vis[x][y]=true;
	for(int k=0;k<4;k++)
	{
		int nx=x+dx[k],ny=y+dy[k];
		if(not invalid(nx,ny)) dfs(nx,ny);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf(" %s",a[i]);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]=='.' and not vis[i][j]) 
				dfs(i,j),ans++;
	printf("%d",ans);
}