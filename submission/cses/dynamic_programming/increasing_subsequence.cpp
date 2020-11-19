#include "bits/stdc++.h"
using namespace std;

int n,x;
vector <int> v;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		int i=lower_bound(v.begin(),v.end(),x)-v.begin();
		if(i==v.size()) v.push_back(x);
		else v[i]=x;
	}
	printf("%d",v.size());
}