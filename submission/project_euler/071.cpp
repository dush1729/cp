#include "bits/stdc++.h"
using namespace std;
int ans;
double mx;
int main()
{
	for(int d=3;d<=1e6;d++)
	{
		int num=3*d/7,den=d;
		if(num*7==3*den) continue;
		int g=__gcd(num,den);
		num/=g,den/=g;
		if(mx<1.*num/den) mx=1.*num/den,ans=num;
	}
	cout<<ans;
}