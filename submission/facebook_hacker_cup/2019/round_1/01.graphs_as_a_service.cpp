#include "bits/stdc++.h"
using namespace std;
const int N=70,M=1e3+20,MAX=1e8;
int t,tc,n,m,u[M],v[M],c[M],d[N][N];

bool ok()
{
	for(int i=0;i<m;i++)
		if(d[u[i]][v[i]]!=c[i])
			return false;
	return true;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=(i!=j?MAX:0);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u[i],&v[i],&c[i]);
			d[u[i]][v[i]]=c[i];
			d[v[i]][u[i]]=c[i];
		}

		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

		cout<<"Case #"<<++tc<<": ";
		if(not ok()) printf("Impossible\n");
		else
		{
			printf("%d\n",m);
			for(int i=0;i<m;i++) printf("%d %d %d\n",u[i],v[i],c[i]);
		}
	}
}