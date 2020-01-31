#include <bits/stdc++.h>
using namespace std;
const int N=41,MAX=1000000;
int n=40,c[N][N],arr[N],size[N],total;
priority_queue <pair<int,pair<int,int>>> pq;

void initialize()
{
	for(int i=1;i<=n;i++) arr[i]=i,size[i]=1;
}

int root(int i)
{
	return arr[i]==i?i:root(arr[i]);
}

bool cycle(int A,int B)
{
	return root(A)==root(B);
}

void join(int A,int B)
{
	int root_A=root(A);
	int root_B=root(B);
	if(size[root_A]<size[root_B]) arr[root_A]=arr[root_B],size[root_B]+=size[root_A];
	else arr[root_B]=arr[root_A],size[root_A]+=size[root_B];
}

int kruskal()
{
	int ans=0;
	while(not pq.empty())
	{
		int c=pq.top().first;
		int u=pq.top().second.first;
		int v=pq.top().second.second;
		pq.pop();
		
		if(cycle(u,v)) continue;
		join(u,v);
		ans+=c;
	}
	return -ans;
}

int main()
{
	initialize();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(c[i][j]!=MAX) total+=c[i][j];
		}
	}

	total/=2;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(c[i][j]!=MAX)
				pq.push({-c[i][j],{i,j}});

	printf("%d",total-kruskal());
}