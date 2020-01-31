#include "bits/stdc++.h"
using namespace std;
const int N=51;
int a[3]={2,3,4};
long long dp[3][N];
int main()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<N;j++)
			dp[i][j]=1;
	for(int i=0;i<3;i++)
		for(int j=a[i];j<N;j++)
			for(int k=a[i];j-k>=0;k++)
				dp[i][j]+=dp[i][j-k];
	cout<<dp[0][N-1]+dp[1][N-1]+dp[2][N-1]-3<<endl;
}