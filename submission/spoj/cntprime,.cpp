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
#define ct          continue
#define endl        '\n'
#define ret         return
#define rsort(a)    greater<a>
#define nl          if(qf==tr) pr("\n");else cout<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define mod         1000000007
#define tc          int t;if(qf==fl) scanf("%d",&t); else cin>>t;whi(t--)
#define minof(a)    std::numeric_limits<a>::min()
#define maxof(a)    std::numeric_limits<a>::max()
#define setval(a,v) memset(a,v,sizeof(a));

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)

int n,q,i,j,a[10009],tree[40009],lazy[40009];
int ch,x,y,v;
vc <bl> prime(1000009,tr);
void build(int node,int start,int end)
{
    if(start==end) tree[node]=prime[a[start]];
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
void update(int node,int start,int end,int l,int r,int type)
{
    if(lazy[node]!=0)
    {
        if(lazy[node]==-1) tree[node]=0; //change everything NOT prime
        else tree[node]=end-start+1; //change everything to prime
        if(start!=end) lazy[2*node]=lazy[2*node+1]=lazy[node]; //NOT leaf node
        lazy[node]=0;
    }
    if(start>end or start>r or end<l) ret ;
    if(start>=l and end<=r)
    {
        if(type==-1)
        {
            tree[node]=0;
            if(start!=end) lazy[2*node]=lazy[2*node+1]=-1;
        }
        else
        {
            tree[node]=end-start+1;
            if(start!=end) lazy[2*node]=lazy[2*node+1]=1;
        }
        ret ;
    }
    int mid=(start+end)/2;
    update(2*node,start,mid,l,r,type);
    update(2*node+1,mid+1,end,l,r,type);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node,int start,int end,int l,int r)
{
    if(start>end or start>r or end<l) ret 0;
    if(lazy[node]!=0)
    {
        if(lazy[node]==-1) tree[node]=0;
        else tree[node]=end-start+1;
        if(start!=end) lazy[2*node]=lazy[2*node+1]=lazy[node];
        lazy[node]=0;
    }
    if(start>=l and end<=r) ret tree[node];
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    ret p1+p2;
}
int main()
{
    prime[0]=prime[1]=fl;
    for(i=4;i<=1000000;i+=2) prime[i]=fl;
    for(i=3;i<=1000;i+=2)
    {
        if(prime[i])
        {
            for(j=i*i;j<=1000000;j+=i) prime[j]=fl;
        }
        if(i%6==1) i+=2;
    }
    int bzbz=1;
    tc
    {
        sc("%d%d",&n,&q);
        for(i=0;i<n;i++) sc("%d",&a[i]),lazy[i]=0;
        for(;i<=4*n+2;i++) lazy[i]=0;
        build(1,0,n-1);
        pr("Case %d:\n",bzbz++);
        whi(q--)
        {
            sc("%d%d%d",&ch,&x,&y);
            x--;
            y--;
            if(ch==0)
            {
                sc("%d",&v);
                if(prime[v]) update(1,0,n-1,x,y,1);
                else update(1,0,n-1,x,y,-1);
            }
            else pr("%d\n",query(1,0,n-1,x,y));
        }
    }
    ret 0;
}
