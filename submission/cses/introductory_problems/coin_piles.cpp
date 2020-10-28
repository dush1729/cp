#include "bits/stdc++.h"
using namespace std;
 
int t,a,b;
 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if((a+b)%3 or a>2*b or b>2*a) puts("NO");
		else puts("YES");
	}
}