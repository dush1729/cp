#include "bits/stdc++.h"
using namespace std;
vector <int> v;
int ans;

bool is_prime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

void go(int i,int p)
{
	if(1ll*p*v[i]<=1e9) ans++,go(i,p*v[i]);
	if(i+1<v.size()) go(i+1,p);
}

int main()
{
	for(int i=2;i<100;i++)
		if(is_prime(i)) v.push_back(i);

	go(0,1);
	cout<<ans+1<<endl;
}