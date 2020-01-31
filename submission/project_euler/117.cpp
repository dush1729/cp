#include "bits/stdc++.h"
using namespace std;
const int N=51;
int a[3]={2,3,4};
long long dp[N];
int main()
{
	for(int i=0;i<N;i++) dp[i]=1;
	for(int i=2;i<N;i++)
		for(int j=0;j<3;j++)
			for(int k=a[j];i-k>=0;k++)
				dp[i]+=dp[i-k];
	cout<<dp[N-1]<<endl;
}