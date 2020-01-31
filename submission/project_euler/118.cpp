#include "bits/stdc++.h"
using namespace std;
const int N=1e7+1;
string a="123456789";
bool prime[N];
int ans;

bool is_prime(int x)
{
	if(x<2) return false;
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

bool okay(int num,int pv)
{
	if(num<pv) return false;
	if(num<N) return prime[num];
	return is_prime(num);
}

void go(int i,int num,int pv)
{
	if(i==9)
	{
		ans+=okay(num,pv);
		return;
	}
	if(i==8 and pv==0) return;
	go(i+1,num*10+a[i]-'0',pv);
	if(okay(num,pv)) go(i,0,num);
}

int main()
{
	for(int i=2;i<N;i++) prime[i]=true;
	for(int i=2;i*i<N;i++)
		if(prime[i])
			for(int j=i*i;j<N;j+=i)
				prime[j]=false;

	do go(0,0,0);
	while(next_permutation(a.begin(),a.end()));
	cout<<ans<<endl;
}