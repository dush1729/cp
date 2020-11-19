#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,a[N];
long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	sort(a,a+n);
	for(int i=0;i<n;i++) ans+=abs(a[i]-a[n/2]);
	printf("%lld",ans);
}