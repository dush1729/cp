#include "bits/stdc++.h"
using namespace std;
const int N=1e2+1;
int dp[N];
int main()
{
	dp[0]=1;
	for(int i=1;i<100;i++)
		for(int j=i;j<=100;j++)
			dp[j]+=dp[j-i];
	cout<<dp[100];
}