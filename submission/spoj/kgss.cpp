#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int n,i,a[N],q,x,y,p[4];
char type;
struct xyz
{
    int mx1,mx2;
}
tree[N<<2];

void build(int node,int start,int end)
{
    if(start==end)
    {
        tree[node].mx1=a[start];
        tree[node].mx2=-1;
    }
    else
    {
        int mid=(start+end)>>1;
        build(node<<1,start,mid);
        build((node<<1)+1,mid+1,end);

        p[0]=tree[node<<1].mx1;
        p[1]=tree[node<<1].mx2;
        p[2]=tree[(node<<1)+1].mx1;
        p[3]=tree[(node<<1)+1].mx2;

        sort(p,p+4,greater<int>());
        tree[node].mx1=p[0];
        tree[node].mx2=p[1];
    }
}

void update(int node,int start,int end,int idx,int val)
{
    if(start == end) tree[node].mx1=val;
    else
    {
        int mid=(start+end)>>1;
        if(start<=idx and idx<=mid) update(node<<1,start,mid,idx,val);
        else update((node<<1)+1,mid+1,end,idx,val);

        p[0]=tree[node<<1].mx1;
        p[1]=tree[node<<1].mx2;
        p[2]=tree[(node<<1)+1].mx1;
        p[3]=tree[(node<<1)+1].mx2;

        sort(p,p+4,greater<int>());
        tree[node].mx1=p[0];
        tree[node].mx2=p[1];
    }
}

vector <int> query(int node,int start,int end,int l,int r)
{
    if(r<start or end<l) return {};
    if(l<=start and end<=r)
    {
        if(tree[node].mx2==-1) return {tree[node].mx1};
        return {tree[node].mx1,tree[node].mx2};
    }
    int mid=(start+end)>>1;
    vector <int> p1=query(node<<1,start,mid,l,r);
    vector <int> p2=query((node<<1)+1,mid+1,end,l,r);
    p1.insert(p1.end(),p2.begin(),p2.end());
    return p1;
}

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);

    build(1,1,n);

    scanf("%d",&q);
    while(q--)
    {
        scanf(" %c%d%d",&type,&x,&y);
        if(type=='U') update(1,1,n,x,y);
        else
        {
            vector <int> ans=query(1,1,n,x,y);
            sort(ans.begin(),ans.end(),greater<int>());
            printf("%d\n",ans[0]+ans[1]);
        }
    }
}
