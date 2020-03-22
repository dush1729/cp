#include "bits/stdc++.h"
using namespace std;
int t,n,s,c,x,tc;
int main()
{
	ios::sync_with_stdio(false);

	cin>>t;
	while(t--)
	{
		vector <vector <int>> vec;
		map <vector <int>,int> m;

		cin>>n>>s;
		for(int i=0;i<n;i++)
		{
			vector <int> v;
			cin>>c;
			while(c--) cin>>x,v.push_back(x);
			sort(v.begin(),v.end());
			vec.push_back(v);
			m[v]++;
		}

		long long ans=1ll*n*n;
		for(auto v:vec)
		{
			for(int mask=1;mask<(1<<v.size());mask++)
			{
				vector <int> sub;
				for(int i=0;i<v.size();i++)
					if(mask&(1<<i)) sub.push_back(v[i]);
				ans-=m[sub];
			}
		}

		cout<<"Case #"<<++tc<<": "<<ans<<"\n";
	}
}