#include <bits/stdc++.h>
using namespace std;
const int N=1e7;
int i,dp[N],ans;
int f(int x)
{
	if(dp[x]!=-1) return dp[x];
	if(x==89) return 1;
	int s=0,X=x;
	while(x) s+=(x%10)*(x%10), x/=10;
	return dp[X]=f(s);
}
int main()
{
	for(i=2;i<N;i++) dp[i]=-1;
	for(i=2;i<N;i++) ans+=f(i);
	cout<<ans<<endl;
}
