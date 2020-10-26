#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,a[N],sum,s,l,ans;

int main()
{
	scanf("%d%d",&n,&sum);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
		while(l<=i and s>sum) s-=a[l++];
		if(s==sum) ans++;
	}
	printf("%d",ans);
}