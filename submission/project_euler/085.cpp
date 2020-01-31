#include "bits/stdc++.h"
using namespace std;
const int N=2e6;
long long p,mx=LLONG_MAX,ansx,ansy;
int main()
{
	for(int i=1;i*(i+1)/2<=4e6;i++)
	{
		int lo=1,hi=2e3,j;
		while(lo<=hi)
		{
			int mid=(lo+hi)/2;
			p=1ll*i*(i+1)*mid*(mid+1)/4;
			if(p<=N) lo=mid+1;
			else hi=mid-1,j=mid;
		}

		p=1ll*i*(i+1)*j*(j+1)/4;
		if(mx>p-N) mx=p-N,ansx=i,ansy=j;
		p=1ll*i*(i+1)*(j-1)*j/4;
		if(mx>N-p) mx=N-p,ansx=i,ansy=j-1;
	}

	cout<<ansx*ansy;
}