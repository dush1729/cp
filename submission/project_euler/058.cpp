#include "bits/stdc++.h"
using namespace std;
int numerator;

bool prime(int x)
{
	if(x==1) return false;
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}
int main()
{
	for(int n=3;;n+=2)
	{
		for(int j=1;j<=4;j++) numerator+=prime((n-2)*(n-2)+j*(n-1));
		if(numerator*10<2*n-1) return 0 * printf("%d",n);
	}
}