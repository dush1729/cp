#include "bits/stdc++.h"
using namespace std;

string a;
vector <string> ans;

int main()
{
	cin>>a;
	sort(a.begin(),a.end());
	do ans.push_back(a);
	while(next_permutation(a.begin(),a.end()));

	cout<<ans.size()<<"\n";
	for(auto a:ans) cout<<a<<"\n";
}