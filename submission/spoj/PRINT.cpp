#include "bits/stdc++.h"
using namespace std;

const int N=1e6+20;

int t,l,r;
bool b[N];
vector <int> primes;

int main()
{
	int r=sqrtl(INT_MAX);
	for(int i=2;i<=r;i++)
		if(not b[i])
			for(int j=i*i;j<=r;j+=i) b[j]=true;
	for(int i=2;i<=r;i++)
		if(not b[i]) primes.push_back(i);

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++) b[i-l]=true;
		for(auto i:primes)
		{
			int lt=l/i+(l%i!=0);
			int rt=r/i;
			for(int j=max(2,lt);j<=rt;j++) b[j*i-l]=false;
		}
		for(int i=l;i<=r;i++)
			if(b[i-l]) printf("%d\n",i);
	}
}