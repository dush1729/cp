#include "bits/stdc++.h"
using namespace std;

int n,m,x;
multiset <int> ms;

int main()
{
	scanf("%d%d",&n,&m);
	while(n--) scanf("%d",&x),ms.insert(x);
	while(m--)
	{
		scanf("%d",&x);
		auto it=ms.upper_bound(x);
		if(it==ms.begin()) printf("-1\n");
		else
		{
			it--;
			printf("%d\n",*it);
			ms.erase(it);
		}
	}
}