#include "bits/stdc++.h"
using namespace std;
const int N=20;
long long dp[N+1][10][10],ans;
int main()
{
	for(int i=1;i<10;i++) dp[1][0][i]=1;

	for(int i=2;i<=N;i++)
		for(int d1=0;d1<10;d1++)
			for(int d2=0;d2<10;d2++)
				for(int pv=0;d1+d2+pv<10;pv++)
					dp[i][d1][d2]+=dp[i-1][pv][d1];

	for(int d1=0;d1<10;d1++)
		for(int d2=0;d2<10;d2++)
			ans+=dp[N][d1][d2];
	cout<<ans<<endl;
}