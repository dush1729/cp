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
int ha[3000][2000],h,a,i,j;
int bfs()
{
    int ans=1;
    ha[h][a]=1;
    queue <pair<int,int>> q;
    q.push({h,a});
    whi(q.empty()==fl)
    {
        pair <int,int> p=q.front();
        q.pop();
        if(p.ff-5>0 and p.ss-10>0 and ha[p.ff-5+3][p.ss-10+2]==-1)
        {
            ha[p.ff-5+3][p.ss-10+2]=ha[p.ff][p.ss]+2;
            ans=max(ans,ha[p.ff][p.ss]+2);
            q.push({p.ff-5+3,p.ss-10+2});
        }
        if(p.ff-20>0 and ha[p.ff-20+3][p.ss+5+2]==-1)
        {
            ha[p.ff-20+3][p.ss+5+2]=ha[p.ff][p.ss]+2;
            ans=max(ans,ha[p.ff][p.ss]+2);
            q.push({p.ff-20+3,p.ss+5+2});
        }
    }
    ret ans;
}
int main()
{
    tc
    {
        sc("%d%d",&h,&a);
        h+=3;
        a+=2;
        for(i=0;i<2000;i++) for(j=0;j<2000;j++) ha[i][j]=-1;
        pr("%d\n",bfs());
    }
    ret 0;
}
