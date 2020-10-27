#include "bits/stdc++.h"
using namespace std;

const int N=1e3+20,MAX=1e7;

int n,m,sx,sy,ex,ey,dp[N][N],dir[N][N];
char a[N][N];
queue <pair <int,int>> q;
int dx[]={+1,-1, 0, 0};
int dy[]={ 0, 0,+1,-1};
string s="DURL",ans;

void add(int x,int y,int dist,int direction)
{
	dp[x][y]=dist;
	dir[x][y]=direction;
	q.push({x,y});
}

bool invalid(int x,int y)
{
	return min(x,y)<0 or x>=n or y>=m or a[x][y]=='#' or dp[x][y]!=MAX;
}

void bfs()
{
	add(sx,sy,0,0);
	while(not q.empty())
	{
		auto p=q.front();
		int x=p.first,y=p.second;
		q.pop();

		for(int k=0;k<4;k++)
		{
			int nx=x+dx[k],ny=y+dy[k];
			if(invalid(nx,ny)) continue;
			add(nx,ny,dp[x][y]+1,k);
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf(" %s",a[i]);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='A') sx=i,sy=j;
			else if(a[i][j]=='B') ex=i,ey=j;
			dp[i][j]=MAX;
		}
	}

	bfs();
	if(dp[ex][ey]==MAX) return 0 * printf("NO");
	printf("YES\n%d\n",dp[ex][ey]);
	while(ex!=sx or ey!=sy)
	{
		int k=dir[ex][ey];
		ans+=s[k];
		ex-=dx[k],ey-=dy[k];
	}
	reverse(ans.begin(),ans.end());
	printf("%s",ans.c_str());
}