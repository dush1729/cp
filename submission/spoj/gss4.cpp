#include "bits/stdc++.h"
using namespace std;
const int N=1e5+20;
int n,q,t,l,r,i,j,testcase;
long long a[N],tree[N<<2];
set <int> s;

void build(int node,int start,int end)
{
    if(start==end) tree[node]=a[start];
    else
    {
        int mid=(start+end)>>1;
        build(node<<1,start,mid);
        build((node<<1)+1,mid+1,end);
        tree[node]=tree[node<<1]+tree[(node<<1)+1];
    }
}

void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
        a[idx]=val;
        tree[node]=val;
    }
    else
    {
        int mid=(start+end)>>1;
        if(start<=idx and idx<=mid) update(node<<1,start,mid,idx,val);
        else update((node<<1)+1,mid+1,end,idx,val);
        tree[node]=tree[node<<1]+tree[(node<<1)+1];
    }
}

long long query(int node,int start,int end,int l,int r)
{
    if(r<start or end<l) return 0;
    if(l<=start and end<=r) return tree[node];
    int mid=(start+end)>>1;
    long long p1=query(node<<1,start,mid,l,r);
    long long p2=query((node<<1)+1,mid+1,end,l,r);
    return p1+p2;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		s.clear();
		printf("Case #%d:\n",++testcase);
		
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]>1) s.insert(i);
		}
		build(1,1,n);
		
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d",&t,&l,&r);
			if(l>r) swap(l,r);
			if(t==0)
			{
				while(1729)
				{
					auto it=s.lower_bound(l);
					if(it==s.end() or *it>r) break;
					
					l=*it;
					update(1,1,n,l,sqrtl(a[l]));
					if(a[l]<=1) s.erase(it);
					l++;
				}
			}
			else printf("%lld\n",query(1,1,n,l,r));
		}
	}
}
