#include "bits/stdc++.h"
using namespace std;
const int N=1e8;
set <int> s;

bool palin(string a)
{
	string b=a;
	reverse(a.begin(),a.end());
	return b==a;
}

int main()
{
	for(int i=1;i*i<N;i++)
	{
		int sum=i*i;
		for(int j=i+1;sum+j*j<N;j++)
		{
			sum+=j*j;
			if(palin(to_string(sum))) s.insert(sum);
		}
	}

	long long ans=0;
	for(auto i:s) ans+=i;
	cout<<ans<<endl;
}