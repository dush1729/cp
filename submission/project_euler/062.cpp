#include "bits/stdc++.h"
using namespace std;
int ans=INT_MAX;
map <string,vector <int>> m;
int main()
{
	for(int i=100;i<10000;i++)
	{
		string c=to_string(1ll*i*i*i);
		sort(c.begin(),c.end());
		m[c].push_back(i);
	}

	for(auto i:m)
		if(i.second.size()==5)
			for(auto j:i.second) ans=min(ans,j);
	cout<<1ll*ans*ans*ans<<"\n";
}