#include "bits/stdc++.h"
using namespace std;
 
const int N=2e5+20;
 
int n,s;
pair <int,int> p[N];
 
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i].first);
		p[i].second=i+1;
	}
 
	sort(p,p+n);
	for(int l=0,r=n-1;l<r;)
	{
		int sum=p[l].first+p[r].first;
		if(sum<s) l++;
		else if(sum==s) return 0 * printf("%d %d",p[l].second,p[r].second);
		else r--;
	}
	printf("IMPOSSIBLE");
}