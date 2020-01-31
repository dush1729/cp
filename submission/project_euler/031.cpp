#include <bits/stdc++.h>
using namespace std;
const int N=220;
int a[]={1,2,5,10,20,50,100,200},i;
long long dp[N];
int f(int i,int sum)
{
	if(i==8) return sum==200;
	int ans=0;
	for(int j=0;sum+j*a[i]<=200;j++)
		ans+=f(i+1,sum+j*a[i]);
	return ans;
}
int main()
{
	cout<<f(0,0);
}
