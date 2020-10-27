#include "bits/stdc++.h"
using namespace std;

int n;
long long ans;

int main()
{
	cin>>n;
	for(long long p=5;p<=n;p*=5) ans+=n/p;
	cout<<ans;
}