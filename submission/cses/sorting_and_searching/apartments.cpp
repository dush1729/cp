#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,m,k,a[N],b[N],ans;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<m;i++) scanf("%d",&b[i]);

	sort(a,a+n);
	sort(b,b+m);

	for(int j=0,i=0;j<m;j++)
	{
		while(i<n and b[j]-a[i]>k) i++;
		if(i<n and abs(b[j]-a[i])<=k)
		{
			ans++;
			i++;
		}
	}
	printf("%d",ans);
}