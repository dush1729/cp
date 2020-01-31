#include<bits/stdc++.h>
using namespace std;
bool qf=false;      //fast io enabled/disabled

#define input       freopen("in.txt","r",stdin);
#define output      freopen("out.txt","w",stdout);
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);qf=true;

#define sc          scanf
#define pr          printf
#define whi         while
#define ll          long long
#define ull         unsigned long long
#define lld         I64d
#define ff          first
#define ss          second
#define vc          vector
#define pb          push_back
#define ite         iterator
#define str         string
#define bl          bool
#define tr          true
#define fl          false
#define ct          continue;
#define endl        '\n'
#define ret         return
#define rsort(a)    greater<a>
#define nl          if(qf==tr) pr("\n");else cout<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define mod         1000000007
#define tc          int t;if(qf==fl) scanf("%d",&t); else cin>>t;whi(t--)
#define minof(a)    std::numeric_limits<a>::min()
#define maxof(a)    std::numeric_limits<a>::max()

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)

int i,n,q,ch,l,r,tree[3][400099],lazy[400099],temp[3],val;
void build(int node,int start,int end)
{
    if(start==end)
    {
        tree[0][node]=1;
    }
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[0][node]=tree[0][2*node]+tree[0][2*node+1];
    }
}
void update(int node,int start,int end,int l,int r)
{
    if(lazy[node]!=0)
    {
        val=lazy[node];
        if(val%3!=0)
        {
            temp[0]=tree[0][node];
            temp[1]=tree[1][node];
            temp[2]=tree[2][node];
            tree[0][node]=temp[(0+val)%3];
            tree[1][node]=temp[(1+val)%3];
            tree[2][node]=temp[(2+val)%3];
            if(start!=end)
            {
                lazy[2*node]+=val;
                lazy[2*node+1]+=val;
            }
        }
        lazy[node]=0;
    }
    if(start>end or start>r or end<l) ret ;
    if(start>=l and end<=r)
    {
        val=1;
        temp[0]=tree[0][node];
        temp[1]=tree[1][node];
        temp[2]=tree[2][node];
        tree[0][node]=temp[(0+val)%3];
        tree[1][node]=temp[(1+val)%3];
        tree[2][node]=temp[(2+val)%3];
        if(start!=end)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        ret ;
    }
    int mid=(start+end)/2;
    update(2*node,start,mid,l,r);
    update(2*node+1,mid+1,end,l,r);
    tree[0][node]=tree[0][2*node]+tree[0][2*node+1];
    tree[1][node]=tree[1][2*node]+tree[1][2*node+1];
    tree[2][node]=tree[2][2*node]+tree[2][2*node+1];
}
int query(int node,int start,int end,int l,int r)
{
    if(start>end or start>r or end<l) ret 0;
    if(lazy[node]!=0)
    {
        val=lazy[node];
        if(val%3!=0)
        {
            temp[0]=tree[0][node];
            temp[1]=tree[1][node];
            temp[2]=tree[2][node];
            tree[0][node]=temp[(0+val)%3];
            tree[1][node]=temp[(1+val)%3];
            tree[2][node]=temp[(2+val)%3];
            if(start!=end)
            {
                lazy[2*node]+=val;
                lazy[2*node+1]+=val;
            }
        }
        lazy[node]=0;
    }
    if(start>=l and end<=r) ret tree[0][node];
    int mid=(start+end)/2;
    int s1=query(2*node,start,mid,l,r);
    int s2=query(2*node+1,mid+1,end,l,r);
    ret (s1+s2);
}
int main()
{
    sc("%d%d",&n,&q);
    build(1,0,n-1);
    for(i=0;i<q;i++)
    {
        sc("%d%d%d",&ch,&l,&r);
        if(ch==0) //increase
        {
            update(1,0,n-1,l,r);
        }
        else //return numbers such that num%3=0
        {
            pr("%d\n",query(1,0,n-1,l,r));
        }
    }
    ret 0;
}
