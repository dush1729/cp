#include "bits/stdc++.h"
using namespace std;

const int MOD=1e9+7;

int n;

int f(int a) {return a==0?1:(2*f(a-1))%MOD;}

int main()
{
	cin>>n;
	cout<<f(n);
}