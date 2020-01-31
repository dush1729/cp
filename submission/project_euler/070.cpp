#include "bits/stdc++.h"
using namespace std;
const int N=1e7;
int lp[N],ans;
double mn=LLONG_MAX;

bool okay(string a,string b)
{
	sort(a.begin(),a.end()),sort(b.begin(),b.end());
	return a==b;
}

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
		if(okay(to_string(i),to_string(totient)) and mn>1.*i/totient)
			mn=1.*i/totient,ans=i;
	}
	cout<<ans<<endl;
}