#include "bits/stdc++.h"
using namespace std;

int t,n;
string s;

int main()
{
	ios::sync_with_stdio(false);

	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		cin>>n>>s;
		cout<<"Case #"<<tc<<": ";

		int a=count(s.begin(),s.end(),'A'),b=n-a;
		cout<<(abs(a-b)==1?'Y':'N')<<"\n";
	}
}