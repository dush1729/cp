#include <bits/stdc++.h>
using namespace std;
int b[]={1,2,3,5,7,11,13,17};
string a="0123456789";
long long ans;
bool ok()
{
	int j=0;
	string s=a.substr(0,3);
	for(auto i:b)
	{
		if(stoi(s)%i) return false;
		s=a.substr(++j,3);
	}
	return true;
}
int main()
{
	do
		if(ok()) ans+=stoll(a);
	while(next_permutation(a.begin(),a.end()));

	cout<<ans;
}
