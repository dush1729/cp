#include "bits/stdc++.h"
using namespace std;
int t,tc;
string a;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a;

		int c=count(a.begin(),a.end(),'B');
		cout<<"Case #"<<++tc<<": ";
		if(c==a.size()-1) cout<<"N";
		else if(c>=a.size()/2 or c>1) cout<<"Y";
		else cout<<"N";
		cout<<"\n";
	}
}