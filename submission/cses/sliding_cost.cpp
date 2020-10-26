#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pp pair <int,int>

typedef tree<
pp, null_type,
less<pp>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;

const int N=2e5+20;

int n,k,a[N];
ordered_set ms;
long long ans;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	for(int i=0;i<k;i++) ms.insert({a[i],i});

	int old_m=ms.find_by_order((k-1)/2)->first;
	for(int i=0;i<k;i++) ans+=abs(a[i]-old_m);
	printf("%lld ",ans);

	for(int i=k;i<n;i++)
	{
		ms.erase({a[i-k],i-k});
		ms.insert({a[i],i});

		int new_m=ms.find_by_order((k-1)/2)->first;
		ans+=abs(a[i]-new_m)-abs(a[i-k]-old_m);
		if(k%2==0) ans-=new_m-old_m;
		printf("%lld ",ans);

		old_m=new_m;
	}
}