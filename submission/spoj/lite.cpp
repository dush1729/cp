#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int n,m,t,l,r,a[N],tree[N<<2],lazy[N<<2];
void update(int node,int start,int end,int l,int r)
{
    if(lazy[node]&1)
    {
        tree[node]=end-start+1-tree[node];
        if(start!=end)
        {
            lazy[node<<1]++;
            lazy[(node<<1)+1]++;
        }
        lazy[node]=0;
    }
    if(start>end or start>r or end<l) return;
    if(start>=l and end<=r)
    {
        tree[node]=end-start+1-tree[node];
        if(start!=end)
        {
            lazy[node<<1]++;
            lazy[(node<<1)+1]++;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r);
    update((node<<1)+1,mid+1,end,l,r);
    tree[node]=tree[node<<1]+tree[(node<<1)+1];
}

int query(int node,int start,int end,int l,int r)
{
    if(start>end or start>r or end<l) return 0;
    if(lazy[node]&1)
    {
        tree[node]=end-start+1-tree[node];
        if(start!=end)
        {
            lazy[node<<1]++;
            lazy[(node<<1)+1]++;
        }
        lazy[node]=0;
    }
    if(start>=l and end<=r) return tree[node];
    int mid=(start+end)>>1;
    int p1=query(node<<1,start,mid,l,r);
    int p2=query((node<<1)+1,mid+1,end,l,r);
    return (p1 + p2);
}
int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d%d",&t,&l,&r);
        if(t==0) update(1,1,n,l,r);
        else printf("%d\n",query(1,1,n,l,r));
    }
}
