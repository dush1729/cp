#include <bits/stdc++.h>
using namespace std;
const int N=7;
int i,ans;
string a;
bool prime(int x)
{
	int r=sqrt(x),i;
	for(i=2;i<=r;i++)
		if(x%i==0) return false;
	return true;
}
int main()
{
	for(i=0;i<N;i++) a+=i+1+'0';
	
	do if(prime(stoi(a))) ans=max(ans,stoi(a));
	while(next_permutation(a.begin(),a.end()));
	
	cout<<ans;
}
