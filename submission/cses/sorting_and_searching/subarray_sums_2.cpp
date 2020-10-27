#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,sum,x;
long long s,ans;
map <long long,int> m;

int main()
{
	scanf("%d%d",&n,&sum);
	m[s]=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		s+=x;
		ans+=m[s-sum];
		m[s]++;
	}
	printf("%lld",ans);
}