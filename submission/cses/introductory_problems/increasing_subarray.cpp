#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,a[N];
long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		if(a[i]<a[i-1]) ans+=a[i-1]-a[i],a[i]=a[i-1];
	printf("%lld",ans);
}