#include "bits/stdc++.h"
using namespace std;
int t,n,q,l,r,tc;
string a;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>q>>a;
		
		vector <int> dp(n+1,0);
		for(int i=1;i<=n;i++) dp[i]=dp[i-1]^(1<<(a[i-1]-'A'));

		int ans=0;
		while(q--)
		{
			cin>>l>>r;
			int x=dp[r]^dp[l-1];
			if(__builtin_popcount(x)<2) ans++;
		}
		cout<<"Case #"<<++tc<<": "<<ans<<"\n";
	}
}