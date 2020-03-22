#include "bits/stdc++.h"
#define left xo
#define right xoxo
using namespace std;
const int N=5e4+20;
int t,n,r,c,x,y,tc;
char a[N];
map <int,int> left[N],right[N],up[N],down[N];

int get_front(map <int,int> &m,int x)
{
	auto it=m.find(x);
	return it==m.end()?x+1:it->second;
}

int get_back(map <int,int> &m,int x)
{
	auto it=m.find(x);
	return it==m.end()?x-1:it->second;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d %s",&n,&r,&c,&x,&y,a);
		for(int i=1;i<=r;i++) left[i].clear(),right[i].clear();
		for(int i=1;i<=c;i++) up[i].clear(),down[i].clear();

		for(int i=0;i<n;i++)
		{
			char c=a[i];

			int point_left=get_back(left[x],y);
			int point_right=get_front(right[x],y);
			int point_up=get_back(up[y],x);
			int point_down=get_front(down[y],x);

			right[x][point_left]=point_right;
			left[x][point_right]=point_left;
			down[y][point_up]=point_down;
			up[y][point_down]=point_up;

			if(c=='E') y=get_front(right[x],y);
			else if(c=='W') y=get_back(left[x],y);
			else if(c=='S') x=get_front(down[y],x);
			else x=get_back(up[y],x);
		}

		printf("Case #%d: %d %d\n",++tc,x,y);
	}
}
