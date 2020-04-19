#include "bits/stdc++.h"
using namespace std;

const int N=3e2+20;

int t,w,h,l,u,r,d,tc;
bool hole[N][N];
double dp[N][N];

int main()
{
	cout<<fixed<<setprecision(12);
	cin>>t;
	while(t--)
	{
		cin>>w>>h>>l>>u>>r>>d;

		for(int i=1;i<=w;i++)
			for(int j=1;j<=h;j++)
				hole[i][j]=false;
		for(int i=l;i<=r;i++)
			for(int j=u;j<=d;j++)
				hole[i][j]=true;

		if(hole[1][1]) dp[1][1]=0;
		else dp[1][1]=1;
		for(int j=2;j<=h;j++)
			if(dp[1][j-1]==0 or hole[1][j]) dp[1][j]=0;
			else if(w!=1) dp[1][j]=dp[1][j-1]/2;
			else dp[1][j]=dp[1][j-1];
		for(int i=2;i<=w;i++)
			if(dp[i-1][1]==0 or hole[i][1]) dp[i][1]=0;
			else if(h!=1) dp[i][1]=dp[i-1][1]/2;
			else dp[i][1]=dp[i-1][1];

		for(int i=2;i<=w;i++)
		{
			for(int j=2;j<=h;j++)
			{
				if(hole[i][j]) dp[i][j]=0;
				else if(i==w and j==h) dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
				else if(i==w) dp[i][j]=(dp[i-1][j]/2+dp[i][j-1]);
				else if(j==h) dp[i][j]=(dp[i-1][j]+dp[i][j-1]/2);
				else dp[i][j]=(dp[i-1][j]+dp[i][j-1])/2;
			}
		}

		cout<<"Case #"<<++tc<<": "<<dp[w][h]<<"\n";
	}
}