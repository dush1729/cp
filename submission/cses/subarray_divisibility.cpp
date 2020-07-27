#include "bits/stdc++.h"
using namespace std;

int n,x,s;
map <int,int> m={{0,1}};
long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		s=(s+x)%n;
		if(s<0) s+=n;
		m[s]++;
		ans+=m[s]-1;
	}
	printf("%lld",ans);
}