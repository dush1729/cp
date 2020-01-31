#include "bits/stdc++.h"
using namespace std;
const int N=51;
long long dp[N][N],ans;
set <long long> s;

bool sqfr(long long x)
{
	for(int i=2;1ll*i*i<=x;i++)
	{
		int cnt=0;
		while(x%i==0) x/=i,cnt++;
		if(cnt>1) return false;
	}
	return true;
}

int main()
{
	dp[0][0]=1;
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0 or j==i) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			s.insert(dp[i][j]);
		}
	}

	for(auto i:s)
		if(sqfr(i)) ans+=i;
	cout<<ans<<endl;
}