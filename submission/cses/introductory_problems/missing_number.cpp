#include "bits/stdc++.h"
using namespace std;

int n,x,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d",&x);
		ans^=x^i;
	}
	printf("%d",ans^n);
}