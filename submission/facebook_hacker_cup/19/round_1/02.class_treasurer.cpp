#include "bits/stdc++.h"
using namespace std;
const int N=1e6+20,MOD=1e9+7;
int t,tc,n,k,p[N];
string a;
int main()
{
	p[0]=1;
	for(int i=1;i<N;i++) p[i]=(p[i-1]<<1)%MOD;

	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>a;

		int s=0,ans=0;
		for(int i=a.size()-1;i>=0;i--)
		{
			if(a[i]=='A') s=max(0,s-1);
			else s++;
			if(s==k+1)
			{
				ans=(ans+p[i+1])%MOD;
				s=max(0,s-2);
			}
		}

		cout<<"Case #"<<++tc<<": "<<ans<<"\n";
	}
}