#include "bits/stdc++.h"
using namespace std;
const int N=30;
long long dp[N+1][3][2];
//dp[i][a][l] - number of combinations for 'i'th day having 'a' consecutive absents at end and
//'l' denotes whether we came late for a day or not till ith day

long long f(int day)
{
	dp[1][0][0]=1;//O
	dp[1][1][0]=1;//A
	dp[1][0][1]=1;//L
	for(int i=1;i<day;i++)
	{
		dp[i+1][0][0]=dp[i][0][0]+dp[i][1][0]+dp[i][2][0];
		dp[i+1][1][0]=dp[i][0][0];
		dp[i+1][2][0]=dp[i][1][0];

		dp[i+1][0][1]=dp[i][0][0]+dp[i][1][0]+dp[i][2][0]+dp[i][0][1]+dp[i][1][1]+dp[i][2][1];
		dp[i+1][1][1]=dp[i][0][1];
		dp[i+1][2][1]=dp[i][1][1];
	}

	long long ans=0;
	for(int a=0;a<3;a++) for(int l=0;l<2;l++) ans+=dp[day][a][l];
	return ans;
}

int main()
{
	cout<<f(N)<<endl;
}