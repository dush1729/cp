#include "bits/stdc++.h"
using namespace std;
const int N=1e6+1;
int lp[N],ans;
double val,mx;
int main()
{
	for(int i=2;i*i<N;i++)
		if(lp[i]==0)
			for(int j=i*i;j<N;j+=i)
				if(lp[j]==0) lp[j]=i;
	for(int i=2;i<N;i++) if(lp[i]==0) lp[i]=i;

	for(int i=2;i<N;i++)
	{
		int num=i,pv=-1;
		val=1;
		while(num!=1)
		{
			if(lp[num]!=pv) val*=lp[num]/(lp[num]-1.);
			pv=lp[num];
			num/=lp[num];
		}
		if(val>mx) mx=val,ans=i;
	}
	cout<<ans;
}