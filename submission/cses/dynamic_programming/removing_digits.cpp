#include "bits/stdc++.h"
using namespace std;

const int N=1e6+20;

int n,dp[N];

int f(int n)
{
	if(n==0) return 0;

	int &ans=dp[n];
	if(ans) return ans;

	ans=1e9;
	string s=to_string(n);
	for(auto c:s)
	{
		if(c=='0') continue;
		ans=min(ans,f(n-(c-'0'))+1);
	}
	return ans;
}

int main()
{
	cin>>n;
	cout<<f(n);
}