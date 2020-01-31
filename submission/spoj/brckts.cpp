#include<bits/stdc++.h>
using namespace std;
const int N=3e4+20;
int t,T=10,n,i,q,x;
string a;
struct z
{
    int open,close;
}tree[4*N],z1;
void build(int node,int start,int end)
{
    z &p=tree[node];

    if(start==end)
    {
        if(a[start]=='(') p.open=1, p.close=0;
        else p.open=0, p.close=1;
    }
    else
    {
        int mid=(start+end)>>1;
        build(node<<1,start,mid);
        build((node<<1)+1,mid+1,end);

        z &l=tree[node<<1], &r=tree[(node<<1)+1];
        p.open=r.open+max(0,l.open-r.close);
        p.close=l.close+max(0,r.close-l.open);
    }
}
void update(int node,int start,int end,int idx)
{
    z &p=tree[node];

    if(start==end) swap(p.open,p.close);
    else
    {
        int mid=(start+end)>>1;
        if(start<=idx and idx<=mid) update(node<<1,start,mid,idx);
        else update((node<<1)+1,mid+1,end,idx);

        z &l=tree[node<<1], &r=tree[(node<<1)+1];
        p.open=r.open+max(0,l.open-r.close);
        p.close=l.close+max(0,r.close-l.open);
    }
}
z query(int node,int start,int end,int l,int r)
{
    z p=tree[node];

    if(r<start or end<l)
    {
        p.close=p.open=0;
        return p;
    }

    if(l<=start and end<=r) return p;

    int mid=(start+end)>>1;
    z left=query(node<<1,start,mid,l,r);
    z right=query((node<<1)+1,mid+1,end,l,r);

    p.open=right.open+max(0,left.open-right.close);
    p.close=left.close+max(0,right.close-left.open);
    return p;
}
int main()
{
    while(++t<=10)
    {
        printf("Test %d:\n",t);

        scanf("%d",&n);
        cin>>a;
        a="$"+a;
        build(1,1,n);

        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&x);
            if(x!=0) update(1,1,n,x);
            else
            {
                z1=query(1,1,n,1,n);
                if(z1.close==0 and z1.open==0) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
}
