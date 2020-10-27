#include "bits/stdc++.h"
using namespace std;

long long n;

int main()
{
	scanf("%lld",&n);
	while(n!=1)
	{
		printf("%lld ",n);
		if(n%2) n=3*n+1;
		else n>>=1;
	}
	printf("1");
}