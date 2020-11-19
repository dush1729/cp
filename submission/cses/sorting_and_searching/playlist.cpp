#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,a[N],ans;
set <int> s;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	for(int l=0,r=0;r<n;r++)
	{
		while(s.find(a[r])!=s.end())
		{
			s.erase(a[l]);
			l++;
		}
		s.insert(a[r]);
		ans=max(ans,r-l+1);
	}

	printf("%d",ans);
}