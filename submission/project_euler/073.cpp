#include "bits/stdc++.h"
using namespace std;
int ans;
int main()
{
	for(int den=5;den<12001;den++)
	{
		int l=(den+2)/3,r=den/2;
		for(int num=l;num<=r;num++)
			if(__gcd(num,den)==1) ans++;
	}
	cout<<ans<<endl;
}
