#include "bits/stdc++.h"
using namespace std;

const int N=8e5+20;

int t,n;
pair <int,int> p[N];
map <int,int> l,r;

int f(map <int,int> &m,int x) {return m.find(x)==m.end()?0:m[x];}

int main()
{
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++)
	{
		l.clear(),r.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d",&p[i].first,&p[i].second);

		sort(p,p+n);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int x=p[i].first+p[i].second;
			l[x]=max(l[x],f(l,p[i].first)+p[i].second);
			ans=max(ans,l[x]+r[x]);
		}
		for(int i=n-1;i>=0;i--)
		{
			int x=p[i].first-p[i].second;
			r[x]=max(r[x],f(r,p[i].first)+p[i].second);
			ans=max(ans,l[x]+r[x]);
		}

		printf("Case #%d: %d\n",tc,ans);
	}
}