#include "bits/stdc++.h"
using namespace std;
const int N=1e6;
int ans;

int f(int a)
{
	int b=a-2,ans=0;
	while(a>=2)
	{
		while(b>=1 and 1ll*a*a-1ll*b*b<=N) b-=2;
		ans+=(a-b-2)/2;
		a-=2;
	}
	return ans;
}

int main()
{
	cout<<f(N)+f(N-1)<<endl;
}