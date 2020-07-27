#include "bits/stdc++.h"
using namespace std;

const int C=26;

string a,ans;

int main()
{
	cin>>a;

	vector <int> f(C,0);
	for(auto c:a) f[c-'A']++;

	int odd=0,val=-1;
	for(int i=0;i<C;i++)
		if(f[i]&1) odd++,val=i;
	if(odd>1) return 0 * printf("NO SOLUTION");

	for(int i=0;i<C;i++) ans+=string(f[i]/2,i+'A');
	cout<<ans;
	if(odd) cout<<char(val+'A');
	reverse(ans.begin(),ans.end());
	cout<<ans;
}