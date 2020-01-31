#include "bits/stdc++.h"
using namespace std;
const int N=1e5+1;
int lp[N];
vector <pair <int,int>> v;
int main()
{
	for(int i=2;i*i<N;i++)
		if(lp[i]==0)
			for(int j=i*i;j<N;j+=i)
				if(lp[j]==0) lp[j]=i;
	for(int i=2;i<N;i++)
		if(lp[i]==0) lp[i]=i;

	for(int i=1;i<N;i++)
	{
		int radical=1,pv=0;
		for(int j=i;j!=1;j/=lp[j])
		{
			if(lp[j]!=pv) radical*=lp[j];
			pv=lp[j];
		}
		v.push_back({radical,i});
	}

	sort(v.begin(),v.end());
	cout<<v[9999].second<<endl;
}