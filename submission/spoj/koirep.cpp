#include "bits/stdc++.h"
using namespace std;
const int N=1e3+20;
int n,m,x,col[N],ans=INT_MAX;
vector <vector <int>> v;
multiset <pair <int,int>> ms;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		v.push_back({});
		for(int j=0;j<m;j++) scanf("%d",&x),v.back().push_back(x);
		v.back().push_back(INT_MAX);
		sort(v.back().begin(),v.back().end());
	}

	for(int i=0;i<n;i++) ms.insert({-v[i][0],i});
	for(int cnt=0;cnt<n*m;cnt++)
	{
		int mx=-(*ms.begin()).first,mn=-(*--ms.end()).first;
		ans=min(ans,mx-mn);
		int row=(*--ms.end()).second;
		ms.insert({-v[row][++col[row]],row});
		ms.erase(--ms.end());
	}
	printf("%d",ans);
}