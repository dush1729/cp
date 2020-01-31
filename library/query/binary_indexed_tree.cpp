#include<bits/stdc++.h>
using namespace std;

const int N=1e7+20;

int n,tree[N],a[N];

void update(int x,int delta)
{
	for(;x<=n;x+=x&-x) tree[x]+=delta;
}

int query(int x)
{
	int sum=0;
	for(;x>0;x-=x&-x) sum+=tree[x];
	return sum;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(i,a[i]);
	}
	printf("sum of first 3 elements is %d\n",query(3));
	printf("sum of all elements in range [2, 3] is %d\n",query(3)-query(2-1));
}