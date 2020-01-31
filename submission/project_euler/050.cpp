#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+20;
int i,j,mxlen,ans;
vector <int> primes;
bool p[MAX];
int main()
{
	for(i=2;i<MAX;i++) p[i]=true;
	for(i=2;i*i<MAX;i++)
		if(p[i])
			for(j=i*i;j<MAX;j+=i)
				p[j]=false;
	
	for(i=2;i<MAX;i++) if(p[i]) primes.push_back(i);
	
	for(i=0;i<primes.size();i++)
	{
		int sum=0, len=0;
		for(j=i;j<primes.size() and sum+primes[j]<MAX;len++,j++)
		{
			sum+=primes[j];
			if(p[sum] and mxlen<len) mxlen=len, ans=sum;
		}
	}
	
	cout<<ans;
}
