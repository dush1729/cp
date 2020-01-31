#include "bits/stdc++.h"
using namespace std;
int ans=5*20+5*20*(30-5)*20;

int f(int n)
{
	int ans=20;
	for(int i=1;i<n/2;i++) ans*=30;
	return ans;
}

int main()
{
	for(int i=2;i<9;i+=2) ans+=f(i);
	cout<<ans<<endl;
}