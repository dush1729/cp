#include "bits/stdc++.h"
using namespace std;
int t,n,m,q,x,tc;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;
		vector <bool> torn(n+1,false);
		while(m--) cin>>x,torn[x]=true;

		map <int,int> m;
		while(q--)
		{
			cin>>x;
			m[x]++;
		}

		long long ans=0;
		for(auto i:m)
		{
			for(int j=i.first;j<=n;j+=i.first)
				if(not torn[j]) ans+=i.second;
		}
		cout<<"Case #"<<++tc<<": "<<ans<<"\n";
	}
}