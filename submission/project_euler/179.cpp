#include "bits/stdc++.h"
using namespace std;
const int N=1e7;
int dp[N],ans;
int main()
{
	for(int i=2;i<N;i++)
		for(int j=i;j<N;j+=i) dp[j]++;
	for(int i=3;i<N;i++)
		if(dp[i]==dp[i-1]) ans++;
	cout<<ans<<endl;
}