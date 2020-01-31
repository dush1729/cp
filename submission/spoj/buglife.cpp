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
#define rsort       greater<int>()
#define nl          if(qf==tr) pr("\n");else cout<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define mod         1000000007
#define tc          int t;if(qf==fl) scanf("%d",&t); else cin>>t;whi(t--)
#define mnlim(a)    std::numeric_limits<a>::min()
#define mxlim(a)    std::numeric_limits<a>::max()

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)

int n,m,i,x,y,sex[2001],parent[2001];
vc <int> adj[2001];
bl ans;
void init()
{
    ans=tr;
    for(int i=1;i<=n;i++) sex[i]=parent[i]=-1,adj[i].clear();
}
bl assumption(int a)
{
    sex[a]=1;
    queue <int> q;
    int i;
    for(i=0;i<sz(adj[a]);i++) q.push(adj[a][i]),parent[adj[a][i]]=a;
    whi(q.empty()==fl)
    {
        a=q.front();
        q.pop();

        if(sex[a]==-1)
        {
            if(sex[parent[a]]==1) sex[a]=2;
            else sex[a]=1;
            for(i=0;i<sz(adj[a]);i++)
            {
                if(sex[adj[a][i]]==-1)
                {
                    q.push(adj[a][i]);
                    parent[adj[a][i]]=a;
                }
                else if(sex[adj[a][i]]==sex[a]) ret fl;
            }
        }
        else if(sex[a]==sex[parent[a]]) ret fl;
    }
    ret tr;
}
int main()
{
    int bzbz=1;
    tc
    {
        sc("%d%d",&n,&m);
        init();
        for(i=0;i<m;i++)
        {
            sc("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(i=1;i<=n;i++)
        {
            if(sex[i]==-1 and assumption(i)==fl)
            {
                ans=fl;
                break;
            }
        }
        if(ans==fl) pr("Scenario #%d:\nSuspicious bugs found!\n",bzbz++);
        else pr("Scenario #%d:\nNo suspicious bugs found!\n",bzbz++);
    }
    ret 0;
}
