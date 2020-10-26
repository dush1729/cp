#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

const int N=2e5+20;

int n,k,a[N];

typedef tree<
pair <int,int>, null_type,
less<pair <int,int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
ordered_set ms;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<k;i++) ms.insert({a[i],i});

	printf("%d ",ms.find_by_order((k-1)/2)->first);
	for(int i=k;i<n;i++)
	{
		ms.erase({a[i-k],i-k});
		ms.insert({a[i],i});
		printf("%d ",ms.find_by_order((k-1)/2)->first);
	}
}