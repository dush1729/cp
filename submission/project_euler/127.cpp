#include "bits/stdc++.h"
using namespace std;
const int N=120000;
int rad[N],ans;
vector <pair <int,int>> v;
int main()
{
	for(int i=1;i<N;i++) rad[i]=1;
	for(int i=2;i<N;i++)
		if(rad[i]==1)
			for(int j=i;j<N;j+=i)
				rad[j]*=i;
	for(int i=1;i<N;i++) v.push_back({rad[i],i});
	sort(v.begin(),v.end());

	for(int c=3;c<N;c++)
	{
		int val=c/rad[c];
		for(auto j:v)
		{
			if(j.first>=val) break;
			if(2*j.second<c and j.first*rad[c-j.second]<val and __gcd(c,j.second)==1) ans+=c;
		}
	}
	cout<<ans<<endl;
}