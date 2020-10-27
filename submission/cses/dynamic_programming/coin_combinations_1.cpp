#include "bits/stdc++.h"
using namespace std;
 
const int MOD=1e9+7;
 
int n,s,x;
vector <int> v;
 
int main()
{
	cin>>n>>s;
	vector <int> dp(s+1,0);
	dp[0]=1;
 
	while(n--) cin>>x,v.push_back(x);
 
	for(int i=0;i<=s;i++)
		for(auto j:v)
			if(j<=i) dp[i]=(dp[i]+dp[i-j])%MOD;
 
	cout<<dp.back();
}