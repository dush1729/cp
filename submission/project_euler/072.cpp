#include "bits/stdc++.h"
using namespace std;
const int N=1e6+1;
int lp[N];
long long ans;
int main()
{
	for(int i=2;i*i<N;i++)
		if(lp[i]==0)
			for(int j=i*i;j<N;j+=i)
				if(lp[j]==0) lp[j]=i;
	for(int i=2;i<N;i++) if(lp[i]==0) lp[i]=i;

	for(int i=2;i<N;i++)
	{
		int num=i,pv=-1,totient=i;
		while(num!=1)
		{
			if(lp[num]!=pv)
			{
				totient/=lp[num];
				totient*=(lp[num]-1);
			}
			pv=lp[num];
			num/=lp[num];
		}
		ans+=totient;
	}
	cout<<ans<<endl;
}
