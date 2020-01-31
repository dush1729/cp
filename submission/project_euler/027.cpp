#include "bits/stdc++.h"
using namespace std;
const int N=2e5+20;
bool prime[N];
vector <int> b;
int cnt,mx,ans;

void go(int a,int b,int n)
{
	if(n*n+a*n+b>1 and prime[n*n+a*n+b]) cnt++;
	else return;
	go(a,b,n+1);
}

int main()
{
	for(int i=2;i<N;i++) prime[i]=true;
	for(int i=2;i*i<N;i++)
		if(prime[i])
			for(int j=i*i;j<N;j+=i)
				prime[j]=false;

	for(int i=2;i<1e3;i++)
		if(prime[i]) b.push_back(i);

	for(int a=-1e3;a<=1e3;a++)
	{
		for(auto i:b)
		{
			cnt=0;
			go(a,i,0);
			if(mx<cnt) mx=cnt,ans=a*i;
		}
	}

	cout<<ans<<"\n";
}