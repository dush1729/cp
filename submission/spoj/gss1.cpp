#include<bits/stdc++.h>
using namespace std;
const int N=5e4+20,MAX=15007;
int n,q,i,a[N],l,r;
struct z
{
    int lmx,rmx,s,mx;
}tree[4*N];
void build(int node,int start,int end)
{
    if(start==end)
    {
        z &p=tree[node];
        p.s=p.lmx=p.rmx=p.mx=a[start];
    }
    else
    {
        int mid=(start+end)>>1;
        build(node<<1,start,mid);
        build((node<<1)+1,mid+1,end);
        z &p=tree[node], &l=tree[node<<1], &r=tree[(node<<1)+1];

        p.s=l.s+r.s;
        p.lmx=max(l.lmx,l.s+r.lmx);
        p.rmx=max(r.rmx,r.s+l.rmx);
        p.mx=max({l.rmx+r.lmx,l.mx,r.mx});
    }
}
z query(int node,int start,int end,int l,int r)
{
    z p;
    if(r<start or end<l)
    {
        p.lmx=p.rmx=p.s=p.mx=-MAX;
        return p;
    }

    if(l<=start and end<=r) return tree[node];
    int mid=(start+end)>>1;

    z p1=query(node<<1,start,mid,l,r);
    z p2=query((node<<1)+1,mid+1,end,l,r);

    p.s=p1.s+p2.s;
    p.lmx=max(p1.lmx,p1.s+p2.lmx);
    p.rmx=max(p2.rmx,p2.s+p1.rmx);
    p.mx=max({p1.rmx+p2.lmx,p1.mx,p2.mx});

    return p;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);

    build(1,1,n);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,1,n,l,r).mx);
    }
}
