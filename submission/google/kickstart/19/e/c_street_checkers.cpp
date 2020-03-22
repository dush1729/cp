#include "bits/stdc++.h"
using namespace std;
const int N=1e5+20;
int t,l,r,tc;
bool b[N];
vector <int> primes;

int main()
{
	for(int i=2;i<N;i++) b[i]=true;
	for(int i=2;i*i<N;i++)
		if(b[i])
			for(int j=i*i;j<N;j+=i)
				b[j]=false;
	for(int i=2;i<N;i++)
		if(b[i]) primes.push_back(i);

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);

		map <int,vector <int>> m;
		for(auto i:primes)
		{
			int lt=(l+i-1)/i,rt=r/i;
			for(int j=lt;j<=rt;j++) m[j*i].push_back(i);
		}

		int ans=0;
		for(int i=l;i<=r;i++)
		{
			int num=i;
			map <int,int> f;
			for(auto j:m[i])
				while(num%j==0) f[j]++,num/=j;
			if(num!=1) f[num]++;

			int all=1;
			for(auto j:f) all*=(j.second+1);
			int odd=all/(f[2]+1),even=all-odd;
			if(abs(odd-even)<=2) ans++;
		}

		printf("Case #%d: %d\n",++tc,ans);
	}
}