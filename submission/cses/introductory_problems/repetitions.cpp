#include "bits/stdc++.h"
using namespace std;

const int N=1e6+20;

char a[N];
int ans=1;

int main()
{
	scanf(" %s",a);
	int n=strlen(a);
	for(int i=1,l=1;i<n;i++)
		if(a[i]==a[i-1]) ans=max(ans,++l);
		else l=1;
	printf("%d",ans);
}