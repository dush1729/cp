#include "bits/stdc++.h"
using namespace std;

const int N=6e7;

bool b[N];

bool distinct(int x)
{
	string a=to_string(x);
	set <char> s;
	for(auto i:a)
		if(s.find(i)==s.end()) s.insert(i);
		else return false;
	return true;
}

class EllysDifferentPrimes
{
public:
	int getClosest(int n)
	{
		for(int i=2;1ll*i*i<N;i++)
			if(b[i]==false)
				for(int j=i*i;j<N;j+=i)
					b[j]=true;
		b[1]=true;
		for(int d=0;;d++)
		{
			if(n-d>1 and not b[n-d] and distinct(n-d)) return n-d;
			if(not b[n+d] and distinct(n+d)) return n+d;
		}
	}
};

#ifdef LOCAL
int main()
{
	vector <int> v={1,2};
	auto ans=EllysDifferentPrimes().getClosest(100);
	cout<<ans<<endl;
}
#endif