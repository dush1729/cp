#include<bits/stdc++.h>
using namespace std;
int yt=1;           //test variable
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
#define mp          make_pair
#define ff          first
#define ss          second
#define vc          vector
#define pb          push_back
#define ite         iterator
#define str         string
#define bl          bool
#define tr          true
#define fl          false

#define endl        '\n'
#define ret         return
#define rsort       greater<int>()
#define nl          if(qf==tr) pr("\n");else cout<<"\n";
#define test        if(qf==tr) pr("TEST %d\n",yt++);else cout<<"TEST "<<yt++<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define mod         1000000007

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)

#define si(n)       if(qf==fl) sc("%d",&n); else cin>>n;
#define sll(n)      if(qf==fl) sc("%lld",&n); else cin>>n;
#define pi(n)       if(qf==fl) pr("%d ",n); else cout<<n<<" ";
#define pll(n)      if(qf==fl) pr("%lld ",n); else cout<<n<<" ";

#define tc          int t;if(qf==fl) si(t) else cin>>t;whi(t--)
#define ct          continue;
#define debug       system("PAUSE");
int n,e,i,x,y,ans;
vc <int> adj[100000];
vc <bl> visited(100000,fl);
void dfs(int x)
{
    visited[x]=tr;
    int i,l=sz(adj[x]);
    for(i=0;i<l;i++)
    {
        if(visited[adj[x][i]]==fl)
        {
            dfs(adj[x][i]);
        }
    }
}
int main()
{
    tc
    {
        ans=0;
        sc("%d%d",&n,&e);
        for(i=0;i<n;i++) adj[i].clear(),visited[i]=fl;
        for(i=0;i<e;i++)
        {
            sc("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(i=0;i<n;i++)
        {
            if(visited[i]==fl)
            {
                dfs(i);
                ans++;
            }
        }
        pr("%d\n",ans);
    }
    ret 0;
}
