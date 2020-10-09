#include "bits/stdc++.h"
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	if(n==2 or n==3) return 0 * printf("NO SOLUTION");
	for(int i=2;i<=n;i+=2) printf("%d ",i);
	for(int i=1;i<=n;i+=2) printf("%d ",i);
}